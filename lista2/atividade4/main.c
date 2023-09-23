/*
Instruções
No seu repositório de atividades, crie uma pasta chamada atividade4 que contenha os arquivos main.c bubble_sort.h e bubble_sort.c;

O seu programa deve implementar o algoritmo bubble sort para ordenar uma lista de números passados na chamada do programa e imprimir a lista dos números ordenados como saída.
Exemplo:
./main 54 26 93 17 77 31 44 55 20
Saída: 17 20 26 31 44 54 55 77 93

OBS: os números são passados como argumentos na chamada do programa (argv);
*/

#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void imprimir_array(int array[], int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        printf("%d ", array[i]);
    }
}

void casting(int array_int[], char *array_string[], int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        array_int[i] = atoi(array_string[i+1]);
    }
}

int main(int argc, char *argv[]){
    if (argc < 2){
        exit(1);
    }
    
    int tamanho = argc - 1;
    int *array = (int *) calloc(tamanho, sizeof(int));
    
    casting(array, argv, tamanho);    
    bubble_sort(array, tamanho);
    imprimir_array(array, tamanho);

    return 0;
}

