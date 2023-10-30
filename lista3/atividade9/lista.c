#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

NO *criar_no(float valor, NO *proximo_no) {
    NO *no = (NO *) malloc(sizeof(NO));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void inserir_no_finalLista(NO *lista, NO *no) {
    if (lista == NULL) return;
    if (no == NULL) return;

    NO *no_atual = lista;
    while (no_atual->proximo_no != NULL) {
        no_atual = no_atual->proximo_no;
    }

    no_atual->proximo_no = no;
}

void inserir_no_inicioLista(NO *lista, NO *no) {
    if (lista == NULL) return;
    if (no == NULL) return;

    NO *no_copia = criar_no(lista->valor, lista->proximo_no);
    lista->valor = no->valor;
    lista->proximo_no = no_copia;
    
    free(no);
}

void inserir_no_entre_dois_nos(NO *no_anterior, NO *no) {
    no->proximo_no = no_anterior->proximo_no;
    no_anterior->proximo_no = no;
}

void lista_inserir_no_ordenado(NO* lista, NO* no) {
    if (no->valor <= lista->valor) {
        inserir_no_inicioLista(lista , no);
    } else {
        while (lista->proximo_no != NULL) {
            if (lista->proximo_no->valor > no->valor) {
                inserir_no_entre_dois_nos(lista, no);
                return;
            }
            lista = lista->proximo_no;
        }
        lista->proximo_no = no;
    }
}

void imprimir_lista(NO *lista) {
    if (lista == NULL) return;
    
    while (lista != NULL) {
        printf("%.2f\n", lista->valor);
        lista = lista->proximo_no;
    }
}