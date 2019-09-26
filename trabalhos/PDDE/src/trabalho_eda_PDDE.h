#ifndef _trabalho_eda_PDDE_h
#define _trabalho_eda_PDDE_h

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilha_DDE.h"

typedef unsigned short int matrix_type;

typedef struct DescritorMatriz {
    size_t linha;
    size_t coluna;
    size_t tamanho_linha;
    matrix_type **matriz;
} DescritorMatriz;

void inicializar_descritor_matriz(DescritorMatriz *);
void adiciona_matriz(DescritorMatriz *, matrix_type);
void adiciona_linha(DescritorMatriz *);
void print_matriz(DescritorMatriz);
int scanf_file(FILE *, const char *, char *);

void object_size(DescritorMatriz *, size_t , size_t , size_t * );
void find_biggest_object(DescritorMatriz *);


#endif
