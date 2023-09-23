#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* init(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->quatidade_objetos = 0;
    return p;
}

void push(Objeto *o, Pilha *P){
    o->proximo_elemento =  P->topo;
    P->topo = o;
    P->quatidade_objetos++;
}

Objeto *pop(Pilha *P){
    if (P->quatidade_objetos == 0){
        return NULL;
    }

    Objeto *o = P->topo;
    P->topo = o->proximo_elemento;
    P->quatidade_objetos--;
    return o;
}