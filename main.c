#include <stdio.h>
// #include "nru/nru.h"
// #include "lru/lru.h"
// #include "segunda_chance/segunda_chance.h"
#include "page_table/page_table.h"
#include "utils/utils.h"

int main(int argc, char* argv[]){

    Entry *page_table;
    FILE *logFile;
    int alg, page_size, total_memory;
    read_args(argv, &alg, &page_size, &total_memory);
    int num_pages = total_memory/page_size;

    // Inicializa a tabela de páginas invertida
    page_table = (Entry*)malloc(num_pages * sizeof(Entry));
    for (int i = 0; i < num_pages; i++) {
        page_table[i].valid = 0; // Marca todos os quadros como inválidos inicialmente
        page_table[i].r = 0;
        page_table[i].m = 0;
        page_table[i].page_number = i;
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

    ll find = 0, miss = 0;
    unsigned addr;
    char rw;
    int i = 0;
    // inicialize_memory(total_memory, page_size);
    while(fscanf(logFile,"%x %c",&addr,&rw) != EOF) {
        unsigned page = addr >> s;
        
        i++;
    }
    // search_page(1, table, num_pages);
        // ################### nru ###########################


    //     // ################### lru ###########################

    // //     unsigned page_number = addr / page_size;

    // //     struct LruPage *page = lru_find_page(page_number);
    // //     if (page != NULL) {
    // //         // Página já está na memória, mover para o final (mais recentemente usada)
    // //         lru_move_to_tail(page);
    // //         find++;
    // //     } else {
    // //         miss++;
    // //         // Página não está na memória, adicionar nova
    // //         if (is_memory_full()) {
    // //             // Remover a página menos recentemente usada (cabeça)
    // //             lru_remove_page(head);
    // //         }
    // //         struct LruPage *new_page = lru_create_new_page(page_number);
    // //         lru_add_page_to_tail(new_page);
    // //     }

    //     // ################### second chance ###########################
    //     // // printf("Acessando a página %u para %c...\n", addr, rw);
    //     // // Verifica se a página já está na tabela de páginas
    //     // int page_index = sc_find_page(page_table, addr, num_pages);
    //     // if (page_index != -1) {
    //     //     // Página encontrada na tabela
    //     //     // printf("Página %d já está na memória.\n", addr);
    //     //     find++;
    //     //     page_table[page_index].referenced = 1;  // Página foi acessada
    //     // } else {
    //     //     // Página não está na tabela de páginas
    //     //     // printf("Página %d não está na memória. Substituindo...\n", addr);
    //     //     miss++;
    //     //     second_chance(page_table, addr, num_pages);
    //     // }

    //     // // Opcional: Mostrar o estado da tabela de páginas
    //     // printf("Estado atual da tabela de páginas:\n");
    //     // for (int j = 0; j < num_pages; j++) {
    //     //     // printf("Frame %d: Página %d, Referenced: %d, Valid: %d\n", j,
    //     //            page_table[j].page_number, page_table[j].referenced, page_table[j].valid;
    //     // }
    // // }
    // // printf("Find: %lld; Miss: %lld\n", find, miss);
    // // destroy_memory();

    // fclose(logFile);

    // return 0;
}