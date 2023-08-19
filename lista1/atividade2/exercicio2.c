/*
Exercício 2 - Maior e menor elemento do array. Escreva uma função que recebe um array de números inteiros e retorna o menor e o maior elemento do array.

Exemplo: menor_maior_array([5, 7, 9,6])
Saída: 5, 9 
*/

#include <stdio.h>

void min_max_array(int array[], int tamanho){
    
    int i;
    int max = array[0];
    int min = array[0];

    for(i=1;i<tamanho;i++){
        if(max < array[i]){
            max = array[i];
        }
        if(min > array[i]){
            min = array[i];
        }
    }

    printf("%d, %d\n", min, max);

    return;
}

int main(){

    int array[] = {5, 7, 9, 6};
    int tamanho = sizeof(array) / 4;

    min_max_array(array, tamanho); 

    return 0;
}