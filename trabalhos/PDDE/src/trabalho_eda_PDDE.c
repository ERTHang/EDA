#include "trabalho_eda_PDDE.h"

int main() {
    FILE *arquivo_saida;
    FILE *arquivo_entrada;
    DescritorMatriz *descritor_matriz;
    size_t label = 0;
    size_t size = 0;
    Coordenadas mass_center;
    inicializar_descritor_matriz(&descritor_matriz);
    char character;
    arquivo_entrada = fopen(ARQUIVO_ENTRADA, "r");
    while (1) {
        if (fscanf(arquivo_entrada, "%c", &character) == EOF) {
            break;
        }
        adiciona_matriz(descritor_matriz, character);
    }
    fclose(arquivo_entrada);
    wrap_with_zeros(descritor_matriz);
    print_matriz_desc(*descritor_matriz);
    find_biggest_object(descritor_matriz, &label, &size, &mass_center);
    print_matriz_object_with_mass_center(*descritor_matriz, label, mass_center);
    if (label) {
        arquivo_saida = fopen(ARQUIVO_SAIDA, "w+");
        write_object_to_file(arquivo_saida, *descritor_matriz, label);
        fclose(arquivo_saida);
    }
    return 0;
}

void find_biggest_object(DescritorMatriz *descritor_matriz, size_t *label, size_t *size, Coordenadas *mass_center) {
    size_t aux;
    size_t biggest_size = 0;
    size_t biggest_label = 0;
    size_t next_obj_label = 1;
    Coordenadas mass_center_aux;

    for (int i = 0; i < descritor_matriz->linha; i++) {
        for (int j = 0; j < descritor_matriz->tamanho_linha; j++) {
            if (*(*(descritor_matriz->matriz + i) + j) == 1) {
                aux = 0;
                object_size(descritor_matriz, i, j, &aux, ++next_obj_label, &mass_center_aux);
                if (aux > biggest_size) {
                    biggest_size = aux;
                    biggest_label = next_obj_label;
                    mass_center->posicao_i = mass_center_aux.posicao_i;
                    mass_center->posicao_j = mass_center_aux.posicao_j;
                }
            }
        }
    }
    *label = biggest_label;
    *size = biggest_size;
    mass_center->posicao_i = round(mass_center->posicao_i / (long double)*size);
    mass_center->posicao_j = round(mass_center->posicao_j / (long double)*size);
    printf("Maior Objeto tem tamanho: %zu, label: %zu e mass center: (%zu, %zu)\n", *size, *label,
           mass_center->posicao_i, mass_center->posicao_j);
}

void object_size(DescritorMatriz *descritor_matriz, size_t x, size_t y, size_t *size, size_t label,
                 Coordenadas *mass_center) {
    Coordenadas *coordenadas_atuais;
    coordenadas_atuais = (Coordenadas *)alloc_memory(sizeof(Coordenadas));
    DescritorPilha *descritor_pilha = NULL;
    inicializar_pilha(&descritor_pilha);
    if (*(*(descritor_matriz->matriz + x) + y) == 1) {
        *(*(descritor_matriz->matriz + x) + y) = label;
        (*size)++;
        coordenadas_atuais->posicao_i = x;
        mass_center->posicao_i = x;

        coordenadas_atuais->posicao_j = y;
        mass_center->posicao_j = y;

        append_pilha(descritor_pilha, coordenadas_atuais);
        while (1) {
            if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i) + coordenadas_atuais->posicao_j + 1) ==
                1) {
                coordenadas_atuais->posicao_j++;
                marcar_matriz_e_caminho(descritor_pilha, descritor_matriz, coordenadas_atuais, label, size,
                                        mass_center);
            } else if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i + 1) +
                         coordenadas_atuais->posicao_j) == 1) {
                coordenadas_atuais->posicao_i++;
                marcar_matriz_e_caminho(descritor_pilha, descritor_matriz, coordenadas_atuais, label, size,
                                        mass_center);
            } else if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i) + coordenadas_atuais->posicao_j -
                         1) == 1) {
                coordenadas_atuais->posicao_j--;
                marcar_matriz_e_caminho(descritor_pilha, descritor_matriz, coordenadas_atuais, label, size,
                                        mass_center);
            } else if (*(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i - 1) +
                         coordenadas_atuais->posicao_j) == 1) {
                coordenadas_atuais->posicao_i--;
                marcar_matriz_e_caminho(descritor_pilha, descritor_matriz, coordenadas_atuais, label, size,
                                        mass_center);
            } else {
                pop_pilha(descritor_pilha, &coordenadas_atuais);
                if (coordenadas_atuais == NULL) {
                    break;
                }
            }
        }
    }
    free(coordenadas_atuais);
    free_pilha(descritor_pilha);
}

void marcar_matriz_e_caminho(DescritorPilha *descritor_pilha, DescritorMatriz *descritor_matriz,
                             Coordenadas *coordenadas_atuais, size_t label, size_t *size, Coordenadas *mass_center) {
    *(*(descritor_matriz->matriz + coordenadas_atuais->posicao_i) + coordenadas_atuais->posicao_j) = label;
    (*size)++;
    mass_center->posicao_i += coordenadas_atuais->posicao_i;
    mass_center->posicao_j += coordenadas_atuais->posicao_j;
    append_pilha(descritor_pilha, coordenadas_atuais);
}

void print_matriz_object_with_mass_center(DescritorMatriz descritor_matriz, size_t label, Coordenadas mass_center) {
    for (size_t i = 0; i < descritor_matriz.linha; i++) {
        for (size_t j = 0; j < descritor_matriz.coluna; j++) {
            if (i == mass_center.posicao_i && j == mass_center.posicao_j) {
                printf("%s%3zu%s", MASS_CENTER_COLOR, *(*(descritor_matriz.matriz + i) + j), BG_COLOR);
            } else if (*(*(descritor_matriz.matriz + i) + j) == label) {
                printf("%s%3zu%s", OBJECT_COLOR, *(*(descritor_matriz.matriz + i) + j), BG_COLOR);

            } else {
                printf("%3zu", *(*(descritor_matriz.matriz + i) + j));
            }
        }
        printf("\n");
    }
}

void write_object_to_file(FILE *file, DescritorMatriz descritor_matriz, size_t label) {
    // Percorre a matriz normatizada ao wrap
    for (size_t i = 1; i < descritor_matriz.linha - 1; i++) {
        for (size_t j = 1; j < descritor_matriz.tamanho_linha - 1; j++) {
            fprintf(file, "%d", *(*(descritor_matriz.matriz + i) + j) == label ? 1 : 0);
        }
        fprintf(file, "\n");
    }
}
