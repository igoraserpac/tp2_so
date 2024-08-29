#include "nru.h"

unsigned nru(Node *page_table[], int num_frames){
    unsigned class0[num_frames];
    unsigned class1[num_frames];
    unsigned class2[num_frames];
    unsigned class3[num_frames];
    int id0 = 0, id1 = 0, id2 = 0, id3 = 0;
    for(int i = 0; i < num_frames; i++){
        Node* atual = page_table[i];
        while(atual != NULL){
            if(atual->value.m == 0 && atual->value.r == 0){
                class0[id0] = atual->value.virtual_page_number;
                id0++;
            }else if(atual->value.m == 1 && atual->value.r == 0){
                class1[id1] = atual->value.virtual_page_number;
                id1++;
            }else if(atual->value.m == 0 && atual->value.r == 1){
                class2[id2] = atual->value.virtual_page_number;
                id2++;
            }else if(atual->value.m == 1 && atual->value.r == 1){
                class3[id3] = atual->value.virtual_page_number;
                id3++;
            }
            atual = atual->next;
        }
    }
    if(id0) return class0[0];
    if(id1) return class1[0];
    if(id2) return class2[0];
    if(id3) return class3[0];
    return 0;
}


void routine(Node* page_table[], unsigned TABLE_SIZE){
    for(int i = 0; i < TABLE_SIZE; i++){    
        Node* atual = page_table[i];
        while(atual != NULL){    
            atual->value.r = 0;
            atual = atual->next;
        }
    }
}
