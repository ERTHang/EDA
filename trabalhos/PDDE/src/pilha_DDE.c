#include "pilha_DDE.h"

void inicializar_pilha(DescritorPilha** descritor_pilha) {
    (*descritor_pilha) = (DescritorPilha*)malloc(sizeof(DescritorPilha));
    (*descritor_pilha)->topo = NULL;
    printf("Descritor Pilha Criado\n");
}
void append_pilha(DescritorPilha* descritor_pilha, Coordenadas* coordenadas) {
    Nodo* nodo;
    nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->anterior = descritor_pilha->topo;
    nodo->proximo = NULL;
    memcpy(&(nodo->coordenadas), coordenadas, sizeof(Coordenadas));
    if (descritor_pilha->topo != NULL) {
        descritor_pilha->topo->proximo = nodo;
    }
    descritor_pilha->topo = nodo;
    printf("Coordenadas %zu %zu adicionadas\n", descritor_pilha->topo->coordenadas.posicao_i, descritor_pilha->topo->coordenadas.posicao_j);
}
void pop_pilha(DescritorPilha* descritor_pilha, Coordenadas* coordenadas) {
    if(descritor_pilha->topo == NULL){
        coordenadas = NULL;
        return;
    }
    Nodo* nodo;
    memcpy(coordenadas, &(descritor_pilha->topo->coordenadas), sizeof(Coordenadas));
    nodo = descritor_pilha->topo;
    descritor_pilha->topo = nodo->anterior;
    printf("Coordenadas %zu %zu adicionadas\n", coordenadas->posicao_i, coordenadas->posicao_j);
    free(nodo);
}
