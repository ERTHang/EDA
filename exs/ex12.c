#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arq.h"

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    Descritor descritor;
    Diamante diamantes[] = {
        {58},
        {18},
        {28},
        {38},
        {48},
        {68},
        {578},
        {585},
        {5844},
        {589231},
        {584796},
        {5884231},
        {58312},
        {588654},
        {5865412},
        {58821},
        {5887965},
        {5868451},
        {58612},
        {586845},
    };
    Anel aneis[] = {
        {1},
        {12},
        {13},
        {14},
        {15},
        {16},
        {186},
        {17},
        {12},
        {16},
        {135},
        {146},
        {1952},
        {1032},
        {1165},
        {16541},
        {13210},
        {165},
        {1321},
        {19841},
    };

    qsort(aneis, 20, sizeof(Anel), cmpfunc);
    qsort(diamantes, 20, sizeof(Diamante), cmpfunc);

    criar_descritor(&descritor);
    for(size_t i = 0; i < 20; i++){
        Par par;
        par.anel = aneis[i];
        par.diamante = diamantes[i];
        Nodo nodo;
        memcpy(&(nodo.par), &par, sizeof(par));
        inserir(&nodo, &descritor);
    }
}

void criar_descritor(Descritor *descritor) {
    descritor = (Descritor *)malloc(sizeof(Descritor));
    descritor->saida = NULL;
    descritor->entrada = NULL;
    descritor->tamanho = 0;
}
void destruir(Descritor *descritor) {
    if (descritor->entrada) {
        Nodo *aux;
        memcpy(aux, descritor->entrada, sizeof(Nodo));
        while (aux) {
            aux = aux->proximo;
            free(aux->anterior);
        }
    }
    free(descritor);
}
void inserir(Nodo *novo_nodo, Descritor *descritor) {
    Nodo *aux;
    memcpy(aux, novo_nodo, sizeof(Nodo));
    aux->anterior = NULL;
    aux->proximo = descritor->entrada;
    if (descritor->entrada) {
        descritor->entrada->anterior = aux;
    }
    descritor->entrada = aux;
    descritor->tamanho++;
}
void remover(Nodo *destino_nodo, Descritor *descritor) {
    memcpy(destino_nodo, descritor->saida, sizeof(Nodo));
    descritor->saida = descritor->saida->anterior;
    free(descritor->saida->proximo);
    descritor->saida->proximo = NULL;
    descritor->tamanho--;
}
void busca(Nodo *destino_nodo, Descritor *descritor, size_t index) {
    if (index >= descritor->tamanho && descritor->tamanho <= 0) {
        printf("INVALIDO");
        return;
    }
    Nodo *aux = NULL;
    if (index > descritor->tamanho / 2) {
        memcpy(aux, descritor->saida, sizeof(Nodo));
        for (size_t i = descritor->tamanho - 1; i > index; i--) {
            aux = aux->proximo;
        }
    } else {
        memcpy(aux, descritor->entrada, sizeof(Nodo));
        for (size_t i = 2; i < index; i++) {
            aux = aux->anterior;
        }
    }
    memcpy(destino_nodo, aux, sizeof(Nodo));
}