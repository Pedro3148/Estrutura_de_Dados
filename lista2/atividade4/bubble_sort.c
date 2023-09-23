#include "bubble_sort.h"

void swap(int *n1, int *n2){
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux; 
}

void bubble_sort(int array[], int tamanho){
    int i, j;
    for (i = 0; i < tamanho - 1; i++){
        for (j = 0; j < tamanho - 1 - i; j++){
            if(array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}