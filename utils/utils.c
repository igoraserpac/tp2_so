#include "utils.h"

void read_args(char *args[], int *algorithm, int *pageSize, int *totalMemory){
    // Mapeia o algoritmo para um valor inteiro
    if (strcmp(args[1], "nru") == 0) {
        *algorithm = 1;
    } else if (strcmp(args[1], "lru") == 0) {
        *algorithm = 2;
    } else if (strcmp(args[1], "segunda_chance") == 0) {
        *algorithm = 3;
    } else {
        fprintf(stderr, "Algoritmo inválido: %s\n", args[1]);
        exit(EXIT_FAILURE);
    }

    

    // Converte o terceiro argumento (tamanho da página) de KB para B
    *pageSize = atoi(args[3]) * 1024;
    if (*pageSize <= 0) {
        fprintf(stderr, "Tamanho da página inválido.\n");
        exit(EXIT_FAILURE);
    }

    // Converte o quarto argumento (tamanho total da memória) de KB para B
    *totalMemory = atoi(args[4]) * 1024;
    if (*totalMemory <= 0) {
        fprintf(stderr, "Tamanho total da memória inválido.\n");
        exit(EXIT_FAILURE);
    }
}