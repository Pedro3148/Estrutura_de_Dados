#include <stdio.h>
#include "selection_sort.h"

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


void selection_sort(int *array, int length) {
    int i, j, menor;

    for (i = 0; i < length - 1; i++) {
        menor = i;
        for (j = i + 1; j < length; j++) {
            if (array[j] < array[menor]) 
                menor = j;
        }
        if (i != menor) 
            swap(&array[i], &array[menor]);
    }
}