#include "matriz.h"

void inicializar_descritor_matriz(DescritorMatriz **desc) {
    *desc = (DescritorMatriz *)alloc_memory(sizeof(DescritorMatriz));
    (*desc)->coluna = 0;
    (*desc)->linha = 0;
    (*desc)->tamanho_linha = 0;
    (*desc)->matriz = NULL;
}

void adiciona_matriz(DescritorMatriz *descritor_matriz, char valor) {
    if (valor == '\n') {
        if (descritor_matriz->tamanho_linha == 0) {
            descritor_matriz->tamanho_linha = descritor_matriz->coluna;
        }
        return;
    }
    if (descritor_matriz->linha == 0 || descritor_matriz->coluna == descritor_matriz->tamanho_linha) {
        adiciona_linha(descritor_matriz);
    }
    if (descritor_matriz->coluna == 0 && descritor_matriz->tamanho_linha > 0) {
        *(descritor_matriz->matriz + descritor_matriz->linha - 1) = (size_t *)calloc_memory(sizeof(size_t), descritor_matriz->tamanho_linha);
    } else if (descritor_matriz->coluna == 0 && descritor_matriz->tamanho_linha == 0) {
        *(descritor_matriz->matriz + descritor_matriz->linha - 1) = (size_t *)alloc_memory(sizeof(size_t));
    } else if (descritor_matriz->tamanho_linha == 0) {
        *(descritor_matriz->matriz + descritor_matriz->linha - 1) = (size_t *)realloc_memory(
            *(descritor_matriz->matriz + descritor_matriz->linha - 1), sizeof(size_t) * (descritor_matriz->coluna + 1));
    }
    *(*((descritor_matriz->matriz) + (descritor_matriz->linha - 1)) + (++(descritor_matriz->coluna) - 1)) = (size_t)(valor - '0');
}

void adiciona_linha(DescritorMatriz *descritor_matriz) {
    if (descritor_matriz->linha == 0) {
        descritor_matriz->matriz = (size_t **)alloc_memory(sizeof(size_t *));
        ++(descritor_matriz->linha);
    } else {
        descritor_matriz->matriz =
            (size_t **)realloc_memory(descritor_matriz->matriz, sizeof(size_t *) * ++(descritor_matriz->linha));
    }
    descritor_matriz->coluna = 0;
}
void print_matriz_desc(DescritorMatriz descritor_matriz) {
    for (size_t i = 0; i < descritor_matriz.linha; i++) {
        for (size_t j = 0; j < descritor_matriz.coluna; j++) {
            printf("%3zu", *(*(descritor_matriz.matriz + i) + j));
        }
        printf("\n");
    }
}
void print_matriz(size_t **matriz, size_t linhas, size_t colunas) {
    for (size_t i = 0; i < linhas; i++) {
        for (size_t j = 0; j < colunas; j++) {
            printf("%3zu", *(*(matriz + i) + j));
        }
        printf("\n");
    }
}
void wrap_with_zeros(DescritorMatriz *descritor_matriz) {
    size_t **matriz_aux = NULL;
    size_t i;
    matriz_aux = (size_t **)alloc_memory(sizeof(size_t *) * (descritor_matriz->linha + 2));
    *matriz_aux = (size_t *)calloc_memory(descritor_matriz->tamanho_linha + 2, sizeof(size_t));
    for (i = 1; i < descritor_matriz->linha + 1; i++) {
        *(matriz_aux + i) = (size_t *)calloc_memory(descritor_matriz->tamanho_linha + 2, sizeof(size_t));
        memcpy(*(matriz_aux + i) + 1, *(descritor_matriz->matriz + i - 1),
               sizeof(size_t *) * descritor_matriz->tamanho_linha);
    }
    *(matriz_aux + i) = (size_t *)calloc_memory(descritor_matriz->tamanho_linha + 2, sizeof(size_t));
    memcpy(&(descritor_matriz->matriz), &matriz_aux, sizeof(size_t **));
    descritor_matriz->coluna += 2;
    descritor_matriz->linha += 2;
    descritor_matriz->tamanho_linha += 2;
}

void free_matriz(DescritorMatriz* descritor_matriz){
    reset_matriz(descritor_matriz);
    free(descritor_matriz);
}

void reset_matriz(DescritorMatriz * descritor_matriz){
    for (size_t i = 0; i < descritor_matriz->linha; i++)
    {
        free(*(descritor_matriz->matriz + i))        ;
    }
    free(descritor_matriz->matriz);
}
