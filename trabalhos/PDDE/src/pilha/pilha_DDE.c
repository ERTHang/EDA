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
    memcpy(*coordenadas, &(descritor_pilha->topo->coordenadas), sizeof(Coordenadas));
    nodo = descritor_pilha->topo;
    descritor_pilha->topo = nodo->anterior;
    free(nodo);
}

void busca_topo(DescritorPilha* descritor_pilha, Coordenadas** coordenadas) {
    if (descritor_pilha->topo == NULL) {
        *coordenadas = NULL;
        return;
    }
    memcpy(*coordenadas, &(descritor_pilha->topo->coordenadas), sizeof(Coordenadas));
}
