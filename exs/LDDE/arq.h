#ifndef _arq_h
#define _arq_h
#include <stddef.h>

typedef struct Valor{
    size_t caixinha_de_valor;
} Valor;

typedef struct Nodo{
    Nodo *proximo;
    Nodo *anterior;
    Valor valor;
}Nodo;

typedef struct Lista{
    size_t tam_info;
    size_t tam_lista;
    Nodo *referencia_movel;
    size_t pos_atual;
}Lista;

int insere_na_pos_log(Lista *, size_t, Valor*);
int busca_na_pos_log(Lista *, size_t, Valor*);

#endif