#ifndef _trabalho_eda_PDDE_h
#define _trabalho_eda_PDDE_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pilha_DDE.h"

#define BG_COLOR "\x1b[0m"
#define OBJECT_COLOR "\x1b[0;32m"
#define MASS_CENTER_COLOR "\x1b[0;35m"

typedef struct DescritorMatriz {
    size_t linha;
    size_t coluna;
    size_t tamanho_linha;
    size_t **matriz;
} DescritorMatriz;

void inicializar_descritor_matriz(DescritorMatriz *);
void adiciona_matriz(DescritorMatriz *, size_t);
void adiciona_linha(DescritorMatriz *);
void print_matriz_desc(DescritorMatriz);
void print_matriz(size_t **, size_t, size_t);

void object_size(DescritorMatriz *, size_t, size_t, size_t *, size_t, Coordenadas *);
void find_biggest_object(DescritorMatriz *, size_t *, size_t *, Coordenadas *);

void write_object_to_file(FILE *, DescritorMatriz, size_t);
void marcar_matriz_e_caminho(DescritorPilha *, DescritorMatriz *, Coordenadas *, size_t, size_t *, Coordenadas *);
void wrap_with_zeros(DescritorMatriz *);

void print_matriz_object_with_mass_center(DescritorMatriz, size_t, Coordenadas);
#endif
