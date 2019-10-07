#include "pilha_DDE.h"

void inicializar_pilha(DescritorPilha** descritor_pilha) {
    *descritor_pilha = (DescritorPilha*)alloc_memory(sizeof(DescritorPilha));
    (*descritor_pilha)->topo = NULL;
}
void append_pilha(DescritorPilha* descritor_pilha, Coordenadas* coordenadas) {
    Nodo* nodo;
    nodo = (Nodo*)alloc_memory(sizeof(Nodo));
    nodo->anterior = descritor_pilha->topo;
    nodo->proximo = NULL;
    memcpy(&(nodo->coordenadas), coordenadas, sizeof(Coordenadas));
    if (descritor_pilha->topo != NULL) {
        descritor_pilha->topo->proximo = nodo;
    }
    descritor_pilha->topo = nodo;
}
void pop_pilha(DescritorPilha* descritor_pilha, Coordenadas** coordenadas) {
    if (descritor_pilha->topo == NULL) {
        *coordenadas = NULL;
        return;
    }
    Nodo* nodo;
    nodo = descritor_pilha->topo->anterior;
    memcpy(*coordenadas, &(descritor_pilha->topo->coordenadas), sizeof(Coordenadas));
    free(descritor_pilha->topo);
    descritor_pilha->topo = nodo;
}

void busca_topo(DescritorPilha* descritor_pilha, Coordenadas** coordenadas) {
    if (descritor_pilha->topo == NULL) {
        *coordenadas = NULL;
        return;
    }
    memcpy(*coordenadas, &(descritor_pilha->topo->coordenadas), sizeof(Coordenadas));
}

void reset_pilha(DescritorPilha * descritor_pilha) {
    struct Nodo *aux = NULL;
    if (descritor_pilha->topo != NULL) {
        aux = descritor_pilha->topo->anterior;
        while (aux != NULL) {
            free(descritor_pilha->topo);
            descritor_pilha->topo = aux;
            aux = aux->anterior;
        }
        free(descritor_pilha->topo);
        descritor_pilha->topo = NULL;
    }
}

void free_pilha(DescritorPilha * descritor_pilha) {
    reset_pilha(descritor_pilha);
    free(descritor_pilha);
}
