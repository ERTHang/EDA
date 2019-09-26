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
    find_biggest_object(&descritor_matriz);
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

void find_biggest_object(DescritorMatriz *descritor_matriz) {
    size_t aux;
    size_t biggest_size = 0;
    for (int i = 0; i < descritor_matriz->linha; i++) {
        for (int j = 0; j < descritor_matriz->tamanho_linha; j++) {
            if (*(*(descritor_matriz->matriz + i) + j) == 1) {
                aux = 0;
                object_size(descritor_matriz, i, j, &aux);
                printf("Objeto encontrado tem tamanho: %zu\n", aux);
                if (aux > biggest_size) {
                    biggest_size = aux;
                }
            }
        }
    }
    printf("Maior Objeto: %zu\n", biggest_size);
}

void object_size(DescritorMatriz *descritor_matriz, size_t x, size_t y, size_t *size) {
    if (*(*(descritor_matriz->matriz + x) + y) == 1) {
        *(*(descritor_matriz->matriz + x) + y) = -1;
        (*size)++;
        if (y + 1 < descritor_matriz->tamanho_linha)
            object_size(descritor_matriz, x, y + 1, size);
        if (x + 1 < descritor_matriz->linha)
            object_size(descritor_matriz, x + 1, y, size);
        if (y > 0)
            object_size(descritor_matriz, x, y - 1, size);
        if (x > 0)
            object_size(descritor_matriz, x - 1, y, size);
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