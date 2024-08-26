// #include "segunda_chance.h"

// void second_chance(Page page_table[], int new_page, int num_pages) {
//     int pointer = 0;  // Apontador para a página mais antiga (candidata à substituição)

//     while (true) {
//         if (page_table[pointer].valid == false || page_table[pointer].referenced == 0) {
//             sc_replace_page(page_table, pointer, new_page);
//             break;
//         } else {
//             page_table[pointer].referenced = 0;  // Dar uma segunda chance
//             pointer = (pointer + 1) % num_pages;  // Avançar o ponteiro ciclicamente
//         }
//     }
// }

// void sc_replace_page(Page page_table[], int page_to_replace, int new_page) {
//     printf("Substituindo a página %d pela página %d.\n", 
//            page_table[page_to_replace].page_number, new_page);
//     page_table[page_to_replace].page_number = new_page;
//     page_table[page_to_replace].referenced = 1;  // Página foi acessada ao ser carregada
//     page_table[page_to_replace].valid = true;
// }

// int sc_find_page(Page page_table[], int page_number, int num_pages) {
//     for (int i = 0; i < num_pages; i++) {
//         if (page_table[i].valid && page_table[i].page_number == page_number) {
//             return i;
//         }
//     }
//     return -1;  // Página não encontrada na tabela
// }