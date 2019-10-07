#ifndef _trabalho_eda_PDDE_h
#define _trabalho_eda_PDDE_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pilha/pilha_DDE.h"
#include "matriz/matriz.h"
#include "mem_allocation/mem_allocation.h"

#define BG_COLOR "\x1b[0m"
#define OBJECT_COLOR "\x1b[0;32m"
#define MASS_CENTER_COLOR "\x1b[0;35m"

#define ARQUIVO_ENTRADA "dados/entrada.txt"
#define ARQUIVO_SAIDA "dados/saida.txt"


void object_size(DescritorMatriz *, size_t, size_t, size_t *, size_t, Coordenadas *);
void find_biggest_object(DescritorMatriz *, size_t *, size_t *, Coordenadas *);

void write_object_to_file(FILE *, DescritorMatriz, size_t);
void marcar_matriz_e_caminho(DescritorPilha *, DescritorMatriz *, Coordenadas *, size_t, size_t *, Coordenadas *);


void print_matriz_object_with_mass_center(DescritorMatriz, size_t, Coordenadas);
#endif
