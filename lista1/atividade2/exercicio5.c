/*
Exercício 5 - Multiplicar elementos de dois arrays. Escreva uma função que recebe dois arrays de números inteiros com o mesmo tamanho e retorna um novo array com os elementos resultantes da multiplicação dos elementos dos dois arrays.

Exemplo: multiplica_array([5, 7, 9, 6], [5, 7, 9,6])
Saída: [25, 49, 81, 36] 
*/

#include <stdio.h>

int *multi_array(int *array1, int *array2, int *multi_array, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        multi_array[i] = array1[i] * array2[i];
    }

    return multi_array;
}

int main(){
    int array1[] = {5, 7, 9, 6};
    int array2[] = {5, 7, 9, 6};
    int tamanho = sizeof(array1) / 4;
    int array_resultante[tamanho];
    int i;

    multi_array(array1, array2, array_resultante, tamanho);
    for(i = 0; i < tamanho; i++){
        printf("%d\n", array_resultante[i]);
    }

    return 0;
}