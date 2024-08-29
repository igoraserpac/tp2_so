#include "nru/nru.h"
#include "lru/lru.h"
#include "segunda_chance/segunda_chance.h"
#include "hash/hash.h"
#include "utils/utils.h"

int main(int argc, char* argv[]){

    FILE *logFile;
    int alg, page_size, total_memory;
    read_args(argv, &alg, &page_size, &total_memory);
    unsigned num_pages = total_memory/page_size;
    Node **page_table = (Node**)malloc(num_pages * sizeof(Node*));
    for (int i = 0; i < num_pages; i++) {
        page_table[i] = NULL;
    }

    // Abre o arquivo de log passado como argumento
    logFile = fopen(argv[2], "r");
    if (logFile == NULL) {
        perror("Erro ao abrir o arquivo de log");
        exit(EXIT_FAILURE);
    }

    unsigned s, tmp;
    /* Derivar o valor de s: */
    tmp = (unsigned)page_size;
    s = 0;
    while (tmp>1) {
        tmp = tmp>>1;
        s++;
    }
    
    ll hit = 0, miss = 0, read = 0, write = 0;
    unsigned addr;
    char rw;
    int free = num_pages;
    int count = 0;
    printf("Executando o simulador... \n");

    if(alg == 1){
        while(fscanf(logFile,"%x %c",&addr,&rw) != EOF) {
            if(rw == 'W') write++;
            else if(rw == 'R') read++;
            int page = addr >> s;
            Node* temp = search(page_table, page, num_pages);
            if(temp == NULL){
                miss++;
                if(free == 0){                
                    unsigned rm = lru(page_table, num_pages);
                    delete(page_table, rm, num_pages);
                    free++;
                }
                insert(page_table, page, num_pages, count);
                free--;
            }else{
                hit++;
            }
        }
    }else if(alg == 2){
        while(fscanf(logFile,"%x %c",&addr,&rw) != EOF) {
            if(rw == 'W') write++;
            else if(rw == 'R') read++;
            int page = addr >> s;
            Node* temp = search(page_table, page, num_pages); 
            if(count>1 && count % 900 == 0){
                routine(page_table, num_pages);
            }
            if(temp == NULL){
                miss++;            
                if(free == 0){                
                    unsigned rm = nru(page_table, num_pages);
                    delete(page_table, rm, num_pages);
                    free++;
                }
                insert(page_table, page, num_pages, count);
                if(rw == 'W'){
                    Node* temp = search(page_table, page, num_pages);
                    temp->value.m = 1;
                }
                free--;
            }else{
                hit++;
            }
            count++;
        }
    }else if(alg == 3){
        Node* page_list = (Node*)malloc(sizeof(Node));
        page_list->next = NULL;
        while(fscanf(logFile,"%x %c",&addr,&rw) != EOF) {
            if(rw == 'W') write++;
            else if(rw == 'R') read++;
            int page = addr >> s;
            Node* temp = search(page_table, page, num_pages);
            
            if(temp == NULL){
                miss++;            
                if(free == num_pages){
                    page_list->value.r = 1;
                    page_list->value.m = 0;
                    page_list->value.valid = 1;
                    page_list->value.virtual_page_number = page;
                    page_list->next = page_list;
                }else if(free == 0){                
                    unsigned rm = second_chance(page_list, page, num_pages);
                    delete(page_table, rm, num_pages);
                    free++;
                }else{
                    Node* atual = page_list;
                    for(int i = 0; i < (num_pages-free)-1; i++){
                        atual = atual->next;
                    }
                    Node* temp = atual->next;
                    atual->next = create_node(page, count);
                    atual->next->next = temp;
                }
                insert(page_table, page, num_pages, count);
                if(rw == 'W'){        
                    Node* temp = search(page_table, page, num_pages);
                    temp->value.m = 1;
                }
                free--;
            }else{
                hit++;
            }
            count++;
        }
    }
    printf(
        "Arquivo de entrada: %s \n"
        "Tamanho da memoria: %u KB \n"
        "Tamanho das paginas: %u KB \n"
        "Tecnica de reposicao: %s \n"
        "Paginas lidas: %lld \n"
        "Paginas escritas: %lld \n"
        "Cache misses: %lld \n"
        "Cache hits: %lld\n", 
        argv[2], 
        total_memory/1024, 
        page_size/1024, 
        argv[1], 
        read, 
        write, 
        miss, 
        hit
    );
    fclose(logFile);

    return 0;
}