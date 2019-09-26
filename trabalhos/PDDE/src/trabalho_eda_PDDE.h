#ifndef _trabalho_eda_PDDE_h
#define _trabalho_eda_PDDE_h

#include "pilha_DDE.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct DescritorMatriz {
    size_t linha;
    size_t coluna;
    size_t tamanho_linha;
    size_t **matriz;
} DescritorMatriz;

void inicializar_descritor_matriz(DescritorMatriz *);
void adiciona_matriz(DescritorMatriz *, size_t);
void adiciona_linha(DescritorMatriz *);
void print_matriz(DescritorMatriz);
int scanf_file(FILE *, const char *, char *);

void object_size(DescritorMatriz *, size_t , size_t , size_t *, size_t);
void find_biggest_object(DescritorMatriz *, size_t*);

void write_object_to_file(FILE*, DescritorMatriz, size_t );


#endif
