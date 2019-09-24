#ifndef _trabalho_eda_PDDE_h
#define _trabalho_eda_PDDE_h
#include <stddef.h>

typedef struct Nodo {
    Nodo *proximo;
    Nodo *anterior;
} Nodo;

typedef struct Descritor {
    Nodo *saida;
    Nodo *entrada;
    size_t tamanho;
} Descritor;

#endif

