// #ifndef LRU_H
// #define LRU_H

// #include <stdio.h>
// #include <stdlib.h>

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// struct LruPage {
//     int page_number;
//     struct LruPage *prev, *next;
// };

// struct LruPage **lru_memory;
// struct LruPage *head = NULL;
// struct LruPage *tail = NULL;
// int current_memory_size = 0;
// int MAX_MEMORY_SIZE = 0;
// int PAGE_SIZE = 0;

// void inicialize_memory(int max_memory_size, int page_size);

// void destroy_memory();

// bool is_memory_full();

// void lru_access_page(int page_number);

// struct LruPage* lru_find_page(int page_number);

// void lru_move_to_tail(struct LruPage *page);

// void lru_remove_page(struct LruPage *page);

// void lru_add_page_to_tail(struct LruPage *page);

// struct LruPage* lru_create_new_page(int page_number);


// #endif