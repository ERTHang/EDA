#ifndef _pilha_DDE_h
#define _pilha_DDE_h

#include <stddef.h>

typedef struct Coordenadas Coordenadas;
typedef struct Nodo Nodo;
typedef struct Descritor Descritor;

struct Coordenadas {
    size_t posicao_i;
    size_t posicao_j;
};

struct Nodo {
    Coordenadas coordenadas;
    Nodo *proximo;
    Nodo *anterior;
};

struct Descritor {
    Nodo *topo;
};

#endif