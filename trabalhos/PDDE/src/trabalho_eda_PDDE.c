#include "trabalho_eda_PDDE.h"

int main() {
    FILE *arquivo_saida;
    FILE *arquivo_entrada;
    arquivo_entrada = fopen("dados/entrada.txt", "r");
    DescritorMatriz descritor_matriz;
    size_t label = 0;
    inicializar_descritor_matriz(&descritor_matriz);
    while (1) {
        char character;
        if (fscanf(arquivo_entrada, "%c", &character) == EOF) {
            break;
        }
        if (character == '\n') {
            if (descritor_matriz.tamanho_linha == -1) {
                descritor_matriz.tamanho_linha = descritor_matriz.coluna;
                printf("Limite Linha: %zu\n", descritor_matriz.tamanho_linha);
            }
        } else {
            adiciona_matriz(&descritor_matriz, (size_t)(character - '0'));
        }
    }
    fclose(arquivo_entrada);
    wrap_with_zeros(&descritor_matriz);
    print_matriz_desc(descritor_matriz);
    find_biggest_object(&descritor_matriz, &label);
    if (label) {
        arquivo_saida = fopen("dados/saida.txt", "w+");
        write_object_to_file(arquivo_saida, descritor_matriz, label);
    }
    return 0;
}

void inicializar_descritor_matriz(DescritorMatriz *desc) {
    desc->coluna = 0;
    desc->linha = 0;
    desc->tamanho_linha = -1;
    desc->matriz = NULL;
}

void adiciona_matriz(DescritorMatriz *descritor_matriz, size_t valor) {
    if (descritor_matriz->linha == 0 || descritor_matriz->coluna == descritor_matriz->tamanho_linha) {
        adiciona_linha(descritor_matriz);
    }
    if (descritor_matriz->coluna == 0) {
        *(descritor_matriz->matriz + descritor_matriz->linha - 1) = (size_t *)malloc(sizeof(size_t));
        ++(descritor_matriz->coluna);
    } else {
        *(descritor_matriz->matriz + descritor_matriz->linha - 1) = (size_t *)realloc(*(descritor_matriz->matriz + descritor_matriz->linha - 1), sizeof(size_t) * ++(descritor_matriz->coluna));
    }
    *(*((descritor_matriz->matriz) + (descritor_matriz->linha - 1)) + (descritor_matriz->coluna - 1)) = valor;
}

void adiciona_linha(DescritorMatriz *descritor_matriz) {
    if (descritor_matriz->linha == 0) {
        descritor_matriz->matriz = (size_t **)malloc(sizeof(size_t *));
        ++(descritor_matriz->linha);
    } else {
        descritor_matriz->matriz = (size_t **)realloc(descritor_matriz->matriz, sizeof(size_t *) * ++(descritor_matriz->linha));
        descritor_matriz->coluna = 0;
    }
}

void find_biggest_object(DescritorMatriz *descritor_matriz, size_t *label) {
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
                    biggest_label = next_obj_label;
                }
            }
        }
    }
    *label = biggest_label;
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
            if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i) + coordenadas_atuais->posicao_j + 1) == 1) {
                coordenadas_atuais->posicao_j++;
                marcar_matriz_e_caminho(descritor_pilha, descritor_matriz, coordenadas_atuais, label, size);
            } else if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i + 1) + coordenadas_atuais->posicao_j) == 1) {
                coordenadas_atuais->posicao_i++;
                marcar_matriz_e_caminho(descritor_pilha, descritor_matriz, coordenadas_atuais, label, size);
            } else if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i) + coordenadas_atuais->posicao_j - 1) == 1) {
                coordenadas_atuais->posicao_j--;
                marcar_matriz_e_caminho(descritor_pilha, descritor_matriz, coordenadas_atuais, label, size);
            } else if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i - 1) + coordenadas_atuais->posicao_j) == 1) {
                coordenadas_atuais->posicao_i--;
                marcar_matriz_e_caminho(descritor_pilha, descritor_matriz, coordenadas_atuais, label, size);
            } else {
                pop_pilha(descritor_pilha, &coordenadas_atuais);
                if (coordenadas_atuais == NULL) {
                    break;
                }
            }
        }
    }
}

void marcar_matriz_e_caminho(DescritorPilha *descritor_pilha, DescritorMatriz *descritor_matriz, Coordenadas *coordenadas_atuais, size_t label, size_t *size) {
    *(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i) + coordenadas_atuais->posicao_j) = label;
    (*size)++;
    append_pilha(descritor_pilha, coordenadas_atuais);
}

void print_matriz_desc(DescritorMatriz descritor_matriz) {
    for (size_t i = 0; i < descritor_matriz.linha; i++) {
        for (size_t j = 0; j < descritor_matriz.coluna; j++) {
            printf("%zu", *(*(descritor_matriz.matriz + i) + j));
        }
        printf("\n");
    }
}

void print_matriz(size_t **matriz, size_t linhas, size_t colunas) {
    for (size_t i = 0; i < linhas; i++) {
        for (size_t j = 0; j < colunas; j++) {
            printf("%zu", *(*(matriz + i) + j));
        }
        printf("\n");
    }
}

void write_object_to_file(FILE *file, DescritorMatriz descritor_matriz, size_t label) {
    // Percorre a matriz normatizada ao wrap
    for (size_t i = 1; i <= descritor_matriz.linha; i++) {
        for (size_t j = 1; j <= descritor_matriz.tamanho_linha; j++) {
            fprintf(file, "%d", *(*(descritor_matriz.matriz + i) + j) == label ? 1 : 0);
        }
        fprintf(file, "\n");
    }
}

void wrap_with_zeros(DescritorMatriz *descritor_matriz) {
    size_t **matriz_aux = NULL;
    size_t i, j;
    matriz_aux = (size_t **)malloc(sizeof(size_t *) * (descritor_matriz->linha + 2));
    *matriz_aux = (size_t *)calloc(descritor_matriz->tamanho_linha + 2, sizeof(size_t));
    for (i = 1; i < descritor_matriz->linha + 1; i++) {
        *(matriz_aux + i) = (size_t *)calloc(descritor_matriz->tamanho_linha + 2, sizeof(size_t));
        for (j = 1; j <= descritor_matriz->tamanho_linha; j++) {
            *(*(matriz_aux + i) + j) = *(*(descritor_matriz->matriz + i - 1) + j - 1);
        }
    }
    *(matriz_aux + i) = (size_t *)calloc(descritor_matriz->tamanho_linha + 2, sizeof(size_t));
    memcpy(&(descritor_matriz->matriz), &matriz_aux, sizeof(size_t **));
}
