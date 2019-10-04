#ifndef _pilha_DDE_h
#define _pilha_DDE_h

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Coordenadas Coordenadas;
typedef struct Nodo Nodo;
typedef struct DescritorPilha DescritorPilha;

struct Coordenadas {
    size_t posicao_i;
    size_t posicao_j;
};

struct Nodo {
    Coordenadas coordenadas;
    Nodo *proximo;
    Nodo *anterior;
};

struct DescritorPilha {
    Nodo *topo;
};

void inicializar_pilha(DescritorPilha **);
void append_pilha(DescritorPilha *, Coordenadas *);
void pop_pilha(DescritorPilha *, Coordenadas **);
void busca_topo(DescritorPilha *, Coordenadas **);
// void clear_pilha(DescritorPilha*);
// void free_pilha(DescritorPilha*);

#endif