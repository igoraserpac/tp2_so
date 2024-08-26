// #include "lru.h"


// void inicialize_memory(int max_memory_size, int page_size){
//     int num_pages = max_memory_size/page_size;
//     MAX_MEMORY_SIZE = num_pages;
//     PAGE_SIZE = page_size;
//     lru_memory = (struct LruPage**)malloc(num_pages * sizeof(struct LruPage*));
//     for(int i = 0; i < num_pages; i++){
//         lru_memory[i] = (struct LruPage*)malloc(sizeof(struct LruPage));
//     }
// }

// void destroy_memory(){
//     for(int i = 0; i < MAX_MEMORY_SIZE; i++){
//         free(lru_memory[i]);
//         // lru_memory[i] = (struct LruPage*)malloc(sizeof(struct LruPage));
//     }
//     free(lru_memory);
//     PAGE_SIZE = 0;
//     MAX_MEMORY_SIZE = 0;
//     // lru_memory = (struct LruPage**)malloc(num_pages * sizeof(struct LruPage*));
    
//     // while (head != NULL) {
//     //     remove_page(head);
//     // }
// }

// struct LruPage* lru_create_new_page(int page_number){
//     struct LruPage *new = (struct LruPage*)malloc(sizeof(struct LruPage));
//     return new;
// }


// bool is_memory_full(){
//     return current_memory_size >= MAX_MEMORY_SIZE;
// }

// void lru_access_page(int page_number) {
//     struct LruPage *current = lru_find_page(page_number);

//     if (current != NULL) {
//         // Página já está na memória, mova para o final
//         lru_move_to_tail(current);
//     } else {
//         // Página não está na memória
//         struct LruPage *new_page = lru_create_new_page(page_number);
//         if (is_memory_full()) {
//             // Remova a página menos recentemente usada (head)
//             lru_remove_page(head);
//         }
//         // Adicione a nova página ao final da lista (tail)
//         lru_add_page_to_tail(new_page);
//     }
// }

// struct LruPage* lru_find_page(int page_number) {
//     struct LruPage *current = head;
//     while (current != NULL) {
//         if (current->page_number == page_number) {
//             return current;
//         }
//         current = current->next;
//     }
//     return NULL;
// }

// void lru_move_to_tail(struct LruPage *page) {
//     // Se já é a tail, não precisa mover
//     if (page == tail) return;

//     // Desvincula a página da sua posição atual
//     if (page->prev != NULL) page->prev->next = page->next;
//     if (page->next != NULL) page->next->prev = page->prev;

//     if (page == head) head = page->next;

//     // Adiciona a página ao final da lista
//     page->prev = tail;
//     page->next = NULL;
//     if (tail != NULL) tail->next = page;
//     tail = page;
// }

// void lru_remove_page(struct LruPage *page) {
//     if (page->prev != NULL) page->prev->next = page->next;
//     if (page->next != NULL) page->next->prev = page->prev;
//     if (page == head) head = page->next;
//     if (page == tail) tail = page->prev;

//     free(page);
// }

// void lru_add_page_to_tail(struct LruPage *page) {
//     page->next = NULL;
//     page->prev= tail;
//     if(tail != NULL) tail->next = page;
//     tail = page;
//     if(head == NULL) head = page;
// }
