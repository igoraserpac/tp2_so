#include "segunda_chance.h"

unsigned second_chance(Node* page_list, unsigned new_page,  unsigned num_pages){
    Node* atual = page_list;
    while(atual != NULL && atual->value.r == 1){
        atual->value.r = 0;
        atual = atual->next;
    }
    unsigned ans = atual->value.virtual_page_number;
    atual->value.virtual_page_number = new_page;
    atual->value.r = 1;
    return ans;
}
