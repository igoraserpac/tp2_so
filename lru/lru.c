#include "lru.h"

unsigned lru(Node* page_table[], unsigned TABLE_SIZE){
    long long last_moment;
    unsigned last_page_num;
    for(int i = 0; i < TABLE_SIZE; i++){    
        if(page_table[i] != NULL){        
            last_moment = page_table[i]->value.count;
            last_page_num = page_table[i]->value.virtual_page_number;
            break;
        }    
    }
    for(int i = 0; i < TABLE_SIZE; i++){    
        Node* atual = page_table[i];
        while(atual != NULL){    
            if(atual->value.count < last_moment){    
                last_moment = atual->value.count;
                last_page_num = atual->value.virtual_page_number;            
                
            }
            atual = atual->next;
        }
    }
    return last_page_num;
}
