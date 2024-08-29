#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Página
typedef struct page {
    int r;
    int m;
    int valid;
    unsigned virtual_page_number;
    long long count;
}Page;

// Estrutura para armazenar uma página
typedef struct Node {
    Page value;
    struct Node* next;
} Node;


// Função hash simples para calcular o índice da chave
unsigned hash(unsigned virtual_page_number, unsigned num_pages);

// Função para criar um novo nó
Node* create_node(unsigned virtual_page_number, long long count);

// Função para inserir um par chave-valor na tabela hash
void insert(Node* hash_table[], unsigned virtual_page_number, unsigned TABLE_SIZE, long long count);

// Função para buscar um valor pela chave
Node* search(Node* hash_table[], unsigned virtual_page_number, unsigned TABLE_SIZE);

// Função para remover uma página pelo numero de página virtual
void delete(Node* hash_table[], unsigned virtual_page_number, unsigned TABLE_SIZE);

// Função para liberar a memória da tabela hash
void free_table(Node* hash_table[], unsigned TABLE_SIZE);

#endif