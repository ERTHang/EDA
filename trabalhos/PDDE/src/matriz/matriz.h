#ifndef _matriz_h
#define _matriz_h
#include <stddef.h>
#include <string.h>
#include "../mem_allocation/mem_allocation.h"

typedef struct DescritorMatriz {
    size_t linha;
    size_t coluna;
    size_t tamanho_linha;
    size_t **matriz;
} DescritorMatriz;

void inicializar_descritor_matriz(DescritorMatriz **);
void adiciona_matriz(DescritorMatriz *, char);
void adiciona_linha(DescritorMatriz *);
void print_matriz_desc(DescritorMatriz);
void print_matriz(size_t **, size_t, size_t);
void wrap_with_zeros(DescritorMatriz *);
void free_matriz(DescritorMatriz*);
void reset_matriz(DescritorMatriz*);

#endif