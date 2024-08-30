#include "hash.h"

unsigned hash(unsigned virtual_page_number, unsigned num_pages) {    
    return ((virtual_page_number+num_pages/5)/3) % num_pages;
}

Node* create_node(unsigned virtual_page_number, long long count) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value.m = 0;
    new_node->value.count = count;
    new_node->value.r = 1;
    new_node->value.valid = 1;
    new_node->value.virtual_page_number = virtual_page_number;
    new_node->next = NULL;
    return new_node;
}

void insert(Node* hash_table[], unsigned virtual_page_number, unsigned s, long long count) {    
    unsigned int index = hash(virtual_page_number, s);        
    Node* new_node = create_node(virtual_page_number, count);
    
    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        new_node->next = hash_table[index];
        hash_table[index] = new_node;
    }
}

Node* search(Node* hash_table[], unsigned virtual_page_number, unsigned s) {    
    unsigned index = hash(virtual_page_number, s);    
    Node* current = hash_table[index];

    while (current != NULL) {
        if (current->value.virtual_page_number == virtual_page_number) {
            return current;
        }
        current = current->next;
    }
    return NULL;  // Retorna NULL se a chave não for encontrada
}

void delete(Node* hash_table[], unsigned virtual_page_number, unsigned s){
    int index = hash(virtual_page_number, s);
    Node* current = hash_table[index];    
    if (current != NULL && current->value.virtual_page_number == virtual_page_number) {    
        hash_table[index] = current->next;
        free(current);
    }else{    
        while (current != NULL && current->next != NULL) {    
            if (current->next->value.virtual_page_number == virtual_page_number) {    
                Node* temp = current->next;    
                current->next = current->next->next;    
                free(temp);
                return;
            }    
            current = current->next;    
        }
    }
}

void free_table(Node* hash_table[], unsigned TABLE_SIZE) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hash_table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hash_table);
}