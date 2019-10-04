#include "pilha_DDE.h"

void inicializar_pilha(DescritorPilha** descritor_pilha) {
    *descritor_pilha = (DescritorPilha*)malloc(sizeof(DescritorPilha));
    if (*descritor_pilha == NULL) {
        fprintf(stderr, "Erro ao alocar descritor Pilha\n");
        exit(EXIT_FAILURE);
    }
    (*descritor_pilha)->topo = NULL;
}
void append_pilha(DescritorPilha* descritor_pilha, Coordenadas* coordenadas) {
    Nodo* nodo;
    nodo = (Nodo*)malloc(sizeof(Nodo));
    if(nodo == NULL){
        fprintf(stderr, "Erro ao alocar descritor Pilha\n");
        exit(EXIT_FAILURE);
    }
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
