#ifndef NRU_H
#define NRU_H

#include "../hash/hash.h"

// Função que escolhe a página a ser removida pelo algoritmo NRU
unsigned nru(Node *page_table[], int num_frames);

// Função que coloca 0 no bit R de todas as entradas, essa função
// é executada a cada 1000 iterações do loop principal
void routine(Node* page_table[], unsigned TABLE_SIZE);

#endif