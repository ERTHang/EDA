#include "trabalho_eda_PDDE.h"

int main() {
    FILE *texto = fopen("dados/entrada.txt", "r");
    DescritorMatriz descritor_matriz;
    inicializar_descritor_matriz(&descritor_matriz);
    while (1) {
        char character;
        if (scanf_file(texto, "%c", &character) == EOF) {
            break;
        }
        if (character == '\n') {
            if (descritor_matriz.tamanho_linha == -1) {
                descritor_matriz.tamanho_linha = descritor_matriz.coluna;
                printf("Limite Linha: %zu\n", descritor_matriz.tamanho_linha);
            }
        } else {
            adiciona_matriz(&descritor_matriz, (int)character - '0');
        }
    }
    fclose(texto);
    print_matriz(descritor_matriz);
    return 0;
}

int scanf_file(FILE *file, const char *format, char *character) {
    return fscanf(file, format, character);
}

void inicializar_descritor_matriz(DescritorMatriz *desc) {
    desc->coluna = 0;
    desc->linha = 0;
    desc->tamanho_linha = -1;
    desc->matriz = NULL;
}

void adiciona_matriz(DescritorMatriz *descritor_matriz, matrix_type valor) {
    if (descritor_matriz->linha == 0 || descritor_matriz->coluna == descritor_matriz->tamanho_linha) {
        adiciona_linha(descritor_matriz);
    }
    if (descritor_matriz->coluna == 0) {
        *(descritor_matriz->matriz + descritor_matriz->linha - 1) = (matrix_type *)malloc(sizeof(matrix_type));
        ++(descritor_matriz->coluna);
    } else {
        *(descritor_matriz->matriz + descritor_matriz->linha - 1) = (matrix_type *)realloc(*(descritor_matriz->matriz + descritor_matriz->linha - 1), sizeof(matrix_type) * ++(descritor_matriz->coluna));
    }
    *(*((descritor_matriz->matriz) + (descritor_matriz->linha - 1)) + (descritor_matriz->coluna - 1)) = valor;
}

void adiciona_linha(DescritorMatriz *descritor_matriz) {
    if (descritor_matriz->linha == 0) {
        descritor_matriz->matriz = (matrix_type **)malloc(sizeof(matrix_type *));
        ++(descritor_matriz->linha);
    } else {
        descritor_matriz->matriz = (matrix_type **)realloc(descritor_matriz->matriz, sizeof(matrix_type *) * ++(descritor_matriz->linha));
        descritor_matriz->coluna = 0;
    }
}

void print_matriz(DescritorMatriz descritor_matriz) {
    for (size_t i = 0; i < descritor_matriz.linha; i++) {
        for (size_t j = 0; j < descritor_matriz.coluna; j++) {
            printf("%hu", *(*(descritor_matriz.matriz + i) + j));
        }
        printf("\n");
    }
}