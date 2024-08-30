#ifndef LRU_H
#define LRU_H
#include "../hash/hash.h"

// Função que escolhe a página a ser removida pelo algoritmo LRU
unsigned lru(Node* page_table[], unsigned TABLE_SIZE);

#endif