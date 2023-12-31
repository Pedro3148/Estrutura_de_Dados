#include <stdio.h>
#include "bubble_sort.h"

void imprimir_array(int array[], int tamanho){
    int i;
    printf("\n");
    for(i = 0; i < tamanho; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(){
    int array[] = {12, 63, 129, 23, 75, 3};
    int tamanho = sizeof(array) / sizeof(int);
    imprimir_array(array, tamanho);
    bubble_sort(array, tamanho);
    imprimir_array(array, tamanho);
    return 0;
}