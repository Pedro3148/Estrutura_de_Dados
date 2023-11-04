#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No *criar_no(char valor, No *proximo_no) {
    No *no = (No *) malloc(sizeof(No));
    if (no != NULL) {
        no->valor = valor;
        no->proximo_no = proximo_no;
    }
    return no;
}

void lista_inserir_no(No *lista, No *no) {
    if (lista == NULL) return;
    if (no == NULL) return;

    while (lista->proximo_no != NULL) {
        lista = lista->proximo_no;
    }
    lista->proximo_no = no;
}

void lista_imprimir(No *lista) {
    if (lista == NULL) return;

    while (lista != NULL) {
        printf("%c ", lista->valor);
        lista = lista->proximo_no;
    }
    printf("\n");
}

int lista_quantidade_no(No *lista) {
    if (lista == NULL) return 0;

    int qtd = 0;
    while (lista != NULL) {
        qtd++;
        lista = lista->proximo_no;
    }
    return qtd;
}

No *copiar_lista(No *lista) {
    No *lista_copia = lista;
    No *l = lista_copia;

    while (lista != NULL) {
        *lista_copia = *lista;
        lista_copia = lista_copia->proximo_no;
        lista = lista->proximo_no;
    }
    return l;
}

void lista_concatenar(No *lista1, No *lista2) {
    while (lista1->proximo_no != NULL) {
        lista1 = lista1->proximo_no;
    }
    lista1->proximo_no = lista2;
}

void lista_liberar(No *lista) {
    if(lista != NULL){
        lista_liberar(lista->proximo_no);
        free(lista);
    }
}

int lista_verificar_existencia(No* lista, char valor_busca) {
    if (lista == NULL) return 0;

    while (lista != NULL) {
        if (valor_busca == lista->valor) 
            return 1;
        lista = lista->proximo_no;
    }
    return 0;
}

int lista_verificar_ocorrencias(No *lista, char valor_busca) {
    if (lista == NULL) return 0;

    int qtd = 0;
    while (lista != NULL) {
        if (lista->valor == valor_busca) 
            qtd++;
        lista = lista->proximo_no;
    }
    return qtd;
}

void lista_imprimir_inversa(No *lista) {
    if (lista != NULL) {
        lista_imprimir_inversa(lista->proximo_no);
        printf("%c ", lista->valor);
    }
}

void lista_inserir_no_i(No *lista, int i) {
    if (lista == NULL) return;
    int index = 0;

    while (lista != NULL) {
        index++;
        if (i == index) {
            inserir_no_entre_dois_nos(lista, criar_no('T', NULL));
            return;
        }
        lista = lista->proximo_no;
    }
}

void inserir_no_entre_dois_nos(No *no_anterior, No *no) {
    no->proximo_no = no_anterior->proximo_no;
    no_anterior->proximo_no = no;
}

void lista_remover_no_i(No* lista, int i) {
    if (i < 0) {
        printf("Posição inválida para remoção.\n");
        return;
    }

    No* atual = lista;

    if (i == 0) {
        lista = lista->proximo_no;
        free(atual);
        return;
    }

    int pos = 0;
    while (atual != NULL && pos < i - 1) {
        atual = atual->proximo_no;
        pos++;
    }

    if (atual == NULL || atual->proximo_no == NULL) {
        printf("Posição inválida para remoção.\n");
        return;
    }

    No* no_a_remover = atual->proximo_no;
    atual->proximo_no = no_a_remover->proximo_no;
    free(no_a_remover);
}

void lista_remover_no(No* lista, char valor_busca) {
    No* atual = lista;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            if (anterior != NULL) {
                anterior->proximo_no = atual->proximo_no;
            } else {
                lista = atual->proximo_no;
            }
            free(atual);
            atual = anterior;
        }
        anterior = atual;
        atual = atual->proximo_no;
    }
}