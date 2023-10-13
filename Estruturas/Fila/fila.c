#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

FILA *criar_fila(){
    FILA *fila = (FILA *) malloc(sizeof(FILA));
    if (fila == NULL) 
        return NULL;
    else {
        fila->qtd_elemento = 0;
        fila->inicio = NULL;
        fila->final = NULL;
    }      
}

int tamanho_fila(FILA *fila) {
    return fila->qtd_elemento;
}

void inserir_fila(FILA *fila, ELEMENTO *elemento) {
    if (fila->qtd_elemento > 0) {
        fila->final->proximo = elemento;
        fila->final = elemento;
    } else {
        fila->inicio = elemento;
        fila->final = elemento;
        elemento->proximo = NULL;
    }
    fila->qtd_elemento++;
}

ELEMENTO *remove_fila(FILA *fila) {
    if (fila == NULL)
        return NULL;
    else {
        ELEMENTO *elemento = fila->inicio;
        fila->inicio = elemento->proximo;
        fila->qtd_elemento--;
        return  elemento;
    }
}