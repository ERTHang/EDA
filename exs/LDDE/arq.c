#include "arq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insere_na_pos_log(Lista *lista, size_t posAlvo, Valor *reg) {
    if (lista->tam_info <= 0 || posAlvo > lista->tam_lista) {
        return 0;
    }
    while (lista->pos_atual != posAlvo) {
        if (lista->pos_atual > posAlvo) {
            lista->referencia_movel = lista->referencia_movel->anterior;
            lista->pos_atual--;
        } else {
            lista->referencia_movel = lista->referencia_movel->proximo;
            lista->pos_atual++;
        }
    }
    Nodo *aux;
    aux = (Nodo *)malloc(sizeof(Nodo));
    aux->proximo = lista->referencia_movel;
    aux->anterior = lista->referencia_movel->anterior;
    aux->anterior->proximo = aux;
    aux->proximo->anterior = aux;
    lista->referencia_movel = aux;
    memcpy(&(aux->valor), reg, lista->tam_info);
}

int busca_na_pos_log(Lista *lista, size_t posAlvo, Valor *reg) {
    if (lista->tam_info <= 0 || posAlvo > lista->tam_lista) {
        return 0;
    }
    while (lista->pos_atual != posAlvo) {
        if (lista->pos_atual > posAlvo) {
            lista->referencia_movel = lista->referencia_movel->anterior;
            lista->pos_atual--;
        } else {
            lista->referencia_movel = lista->referencia_movel->proximo;
            lista->pos_atual++;
        }
    }

    memcpy(reg, &(lista->referencia_movel->valor), lista->tam_info);
    return 1;
}
