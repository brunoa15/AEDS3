#include <stdio.h>
#include <stdlib.h>
#include "lista_pilha_fila.h"

//LISTA-------------------------------------
void lista_FazVazia(t_lista *lista){
    lista->primeiro = malloc(sizeof(t_celula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

int lista_TestaVazia(t_lista lista){
    return (lista.primeiro == lista.ultimo);
}

void lista_InsereFinal(t_item x, t_lista *lista){
    lista->ultimo->prox = malloc(sizeof(t_celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = x;
    lista->ultimo->prox = NULL;
}

void lista_InsereP(t_item x, t_lista *lista, t_apontador p){
    t_apontador novo = malloc(sizeof(t_celula));
    novo->item = x;
    novo->prox = p->prox;
    if (novo->prox == NULL) {
        lista->ultimo = novo;
    }
    p->prox = novo;
}

void lista_RetiraP(t_apontador p, t_lista *L, t_item *item){
    if (lista_TestaVazia(*L) || p == NULL || p->prox == NULL){
        printf("erro lista vazia\n"); return;
    }
    t_apontador q = p->prox;
    *item = q->item;
    p->prox = q->prox;
    if (p->prox == NULL){
        L->ultimo = p;
    }
    free(q);
}

void lista_Imprime(t_lista lista){
    t_apontador p;
    p = lista.primeiro->prox;
    while (p != NULL) {
        printf("%d\n", p->item.chave);
        p = p->prox;
    }
}


//PILHA-------------------------------------
void pilha_FazVazia(t_pilha *pilha){
    pilha->topo = malloc(sizeof(t_celula));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
    pilha->tamanho = 0;
}

int pilha_TestaVazia(t_pilha *pilha){
    return (pilha->topo == pilha->fundo);
}

void pilha_empilha(t_item x, t_pilha *pilha){
    t_apontador aux = malloc(sizeof(t_celula));
    pilha->topo->item = x;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

void pilha_desempilha(t_pilha *pilha, t_item *item){
    if (pilha_TestaVazia(pilha)) {
        fprintf(stderr,"Erro pilha vazia\n");
        exit(-1);
    }
    t_apontador q = pilha->topo;
    pilha->topo = q->prox;
    *item = q->prox->item;
    free(q);
    pilha->tamanho--;
}

int pilha_tamanho(t_pilha *pilha){
    return pilha->tamanho;
}


//FILA--------------------------------------
void fila_FazVazia(t_fila *fila){
    fila->frente = malloc(sizeof(t_celula));
    fila->tras = fila->frente;
    fila->frente->prox = NULL; 
}

int fila_TestaVazia(t_fila *fila){
    return (fila->frente == fila->tras); 
}

void fila_enfileira(t_item x, t_fila *fila){
    fila->tras->prox = malloc(sizeof(t_celula));
    fila->tras = fila->tras->prox;
    fila->tras->item = x;
    fila->tras->prox = NULL; 
}

void fila_desenfileira(t_fila *fila, t_item *item){
    if (fila_TestaVazia(fila)) {
        fprintf(stderr,"Erro: fila vazia\n");
    exit(-1);
    }
    t_apontador q = fila->frente;
    fila->frente = fila->frente->prox;
    *item = fila->frente->item;
    free(q);
}