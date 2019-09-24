#ifndef _arq_h
#define _arq_h
#include <stddef.h>

typedef struct Diamante {
    size_t quilates;
} Diamante;

typedef struct Anel {
    size_t quilates;
} Anel;

typedef struct Par {
    Diamante diamante;
    Anel anel;
} Par;

typedef struct Nodo {
    Par par;
    Nodo *proximo;
    Nodo *anterior;
} Nodo;

typedef struct Descritor {
    Nodo *saida;
    Nodo *entrada;
    size_t tamanho;
} Descritor;

void criar(Descritor *);
void destruir(Descritor *);
void inserir(Nodo *, Descritor *);
void remover(Nodo *, Descritor *);
void busca(Nodo *, Descritor *, size_t);


#endif