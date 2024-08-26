#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long
#define FOR(i,m,n) for(int i = m; i < n; i++)
#define max(a,b) a > b ? a : b
#define min(a,b) a < b ? a : b

void read_args(char *args[], int *algorithm, int *pageSize, int *totalMemory);
// Lê os argumentos da linha de comando e inicializa a leitura do arquivo de entrada;



#endif