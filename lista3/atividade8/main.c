#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    No *lista = criar_no('0', NULL);
    No *n1 = criar_no('1', NULL);
    No *n2 = criar_no('2', NULL);
    No *n3 = criar_no('3', NULL);
    No *n4 = criar_no('4', NULL);
    No *n5 = criar_no('5', NULL);
    No *n6 = criar_no('5', NULL);
    No *n7 = criar_no('5', NULL);
    
    lista_inserir_no(lista, n1);
    lista_inserir_no(lista, n2);
    lista_inserir_no(lista, n3);
    lista_inserir_no(lista, n4);
    lista_inserir_no(lista, n5);
    lista_inserir_no(lista, n6);
    lista_inserir_no(lista, n7);

    printf("Existencia do Valor 4 na Lista: %d\n\n", lista_verificar_existencia(lista, '4'));

    printf("Ocorrencia do Valor 5 na Lista: %d\n\n", lista_verificar_ocorrencias(lista, '5'));

    printf("Lista Inversa: "); lista_imprimir_inversa(lista);

    lista_inserir_no_i(lista, 2);
    printf("\n\nInserir No com valor T na posicao 2: "); lista_imprimir(lista);
    
    lista_remover_no_i(lista, 2);
    printf("\nRemover No na posicao 2: "); lista_imprimir(lista);

    lista_remover_no(lista, '3');
    printf("\nRemover o valor 3 na lista: "); lista_imprimir(lista);
    return 0;
}
