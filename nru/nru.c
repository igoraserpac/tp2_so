// #include "nru.h"
// #include <stdio.h>

// void nru_page_replacement(Page page_table[], int num_pages) {
//     int i;
//     int class0 = -1, class1 = -1, class2 = -1, class3 = -1;
    
//     // Classificação das páginas
//     for (i = 0; i < num_pages; i++) {
//         int R = page_table[i].referenced;
//         int M = page_table[i].modified;
        
//         if (R == 0 && M == 0) {
//             class0 = i;  // Página candidata ideal (Classe 0)
//         } else if (R == 0 && M == 1) {
//             if (class1 == -1) class1 = i;  // Candidata menos ideal (Classe 1)
//         } else if (R == 1 && M == 0) {
//             if (class2 == -1) class2 = i;  // Candidata (Classe 2)
//         } else {
//             if (class3 == -1) class3 = i;  // Menos ideal (Classe 3)
//         }
//     }

//     // Seleção da página a ser substituída
//     if (class0 != -1) {
//         replace_page_nru(class0);
//     } else if (class1 != -1) {
//         replace_page_nru(class1);
//     } else if (class2 != -1) {
//         replace_page_nru(class2);
//     } else {
//         replace_page_nru(class3);
//     }
    
//     // Atualizar bits de referência e modificação
//     for (i = 0; i < num_pages; i++) {
//         page_table[i].referenced = 0;  // Zerar o bit de referência
//     }
// }

// void replace_page_nru(int page_index) {
//     // Lógica para substituir a página na posição page_index
//     printf("Substituindo a página %d\n", page_index);
// }
