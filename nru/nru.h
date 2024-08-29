#ifndef NRU_H
#define NRU_H

#include "../hash/hash.h"

unsigned nru(Node *page_table[], int num_frames);

void routine(Node* page_table[], unsigned TABLE_SIZE);

#endif