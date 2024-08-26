#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa uma entrada na tabela de páginas reversa
typedef struct {
    unsigned int virtual_page_number; // Número da página virtual
    // int process_id;                   // ID do processo ao qual a página pertence
    int valid;                        // Bit válido para indicar se o quadro está em uso
} Entry;

// Função de hash simples para mapeamento
unsigned int hash_function(unsigned int virtual_page_number, int num_frames) {
    return virtual_page_number % num_frames;
}

// Inicializa a tabela de páginas reversa
void initialize_inverted_page_table(Entry *inverted_page_table[], int num_frames) {
    *inverted_page_table = (Entry*)malloc(num_frames * sizeof(Entry));
    for (int i = 0; i < num_frames; i++) {
        (*inverted_page_table)[i].valid = 0; // Marca todos os quadros como inválidos inicialmente
    }
}

// Insere uma nova página na tabela de páginas reversa
int insert_page(unsigned int virtual_page_number, Entry *inverted_page_table[], int num_frames) {
    unsigned int index = hash_function(virtual_page_number, num_frames);
    while ((*inverted_page_table)[index].valid) {
        // Probing linear para lidar com colisões
        index = (index + 1) % num_frames;
    }
    (*inverted_page_table)[index].virtual_page_number = virtual_page_number;
    // (*inverted_page_table)[index].process_id = process_id;
    (*inverted_page_table)[index].valid = 1;

    return index; // Retorna o índice onde a página foi inserida
}

// Busca por uma página na tabela de páginas reversa
int search_page(unsigned int virtual_page_number, Entry inverted_page_table[], int num_frames) {
    unsigned int index = hash_function(virtual_page_number, num_frames);
    unsigned int start_index = index;

    while (inverted_page_table[index].valid) {
        printf("%u\n", inverted_page_table[index].virtual_page_number);
        if (inverted_page_table[index].virtual_page_number == virtual_page_number){
            return index; // Página encontrada
        }
        index = (index + 1) % num_frames;
        if (index == start_index) {
            break; // Voltou ao início, página não encontrada
        }
    }
    return -1; // Página não encontrada
}

// Remove uma página da tabela de páginas reversa
void remove_page(unsigned int virtual_page_number, Entry inverted_page_table[], int num_frames) {
    int index = search_page(virtual_page_number, inverted_page_table, num_frames);
    if (index != -1) {
        inverted_page_table[index].valid = 0; // Marca o quadro como inválido
    }
}
