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
            adiciona_matriz(&descritor_matriz, (matrix_type)(character - '0'));
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
    size_t biggest_label = 0;
    size_t next_obj_label = 1;

    for (int i = 0; i < descritor_matriz->linha; i++) {
        for (int j = 0; j < descritor_matriz->tamanho_linha; j++) {
            if (*(*(descritor_matriz->matriz + i) + j) == 1) {
                aux = 0;
                object_size(descritor_matriz, i, j, &aux, ++next_obj_label);
                printf("Objeto encontrado tem tamanho: %zu\n", aux);
                if (aux > biggest_size) {
                    biggest_size = aux;
                    biggest_label = next_obj_label - 1;
                }
            }
        }
    }
    printf("Maior Objeto tem tamanho: %zu e label: %zu\n", biggest_size, biggest_label);
}

void object_size(DescritorMatriz *descritor_matriz, size_t x, size_t y, size_t *size, size_t label) {
    Coordenadas *coordenadas_atuais;
    coordenadas_atuais = (Coordenadas *)malloc(sizeof(Coordenadas));
    DescritorPilha *descritor_pilha = NULL;
    inicializar_pilha(&descritor_pilha);
    if (*(*(descritor_matriz->matriz + x) + y) == 1) {
        *(*(descritor_matriz->matriz + x) + y) = label;
        (*size)++;
        coordenadas_atuais->posicao_i = x;
        coordenadas_atuais->posicao_j = y;
        append_pilha(descritor_pilha, coordenadas_atuais);
        while (1) {
            matrix_type checou = 0;
            if (coordenadas_atuais->posicao_j + 1 < descritor_matriz->tamanho_linha && !checou) {
                if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i) + coordenadas_atuais->posicao_j + 1) == 1) {
                    coordenadas_atuais->posicao_j++;
                    checou = 1;
                }
            }
            if (coordenadas_atuais->posicao_i + 1 < descritor_matriz->linha && !checou) {
                if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i + 1) + coordenadas_atuais->posicao_j) == 1) {
                    coordenadas_atuais->posicao_i++;
                    checou = 1;
                }
            }
            if (coordenadas_atuais->posicao_j > 0 && !checou) {
                if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i) + coordenadas_atuais->posicao_j - 1) == 1) {
                    coordenadas_atuais->posicao_j--;
                    checou = 1;
                }
            }
            if (coordenadas_atuais->posicao_i > 0 && !checou) {
                if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i - 1) + coordenadas_atuais->posicao_j) == 1) {
                    coordenadas_atuais->posicao_i--;
                    checou = 1;
                }
            }
            if (!checou) {
                pop_pilha(descritor_pilha, coordenadas_atuais);
                if (coordenadas_atuais == NULL) {
                    break;
                }
            } else {
                *(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i) + coordenadas_atuais->posicao_j) = label;
                (*size)++;
                append_pilha(descritor_pilha, coordenadas_atuais);
            }
        }
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