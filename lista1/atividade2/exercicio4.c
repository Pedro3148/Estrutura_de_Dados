/*
Exercício 4 - Contar a quantidade de ocorrências de um elemento no array. Escreva uma função que recebe um array de números inteiros e um número inteiro de busca, e retorna a quantidade de vezes que o número de busca aparece no array.

Exemplo: conta_int_array([5, 7, 9, 6, 7, 11, 6, 5], 7)
Saída: 2
*/

#include <stdio.h>

int qtdd_num(int array[], int tamanho, int num){
    int frequencia = 0;
    int i;

    for(i=0;i<tamanho;i++){
        if(array[i] == num){
            frequencia++;
        }
    }

    return frequencia;
}

int main(){

    int array[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int tamanho = sizeof(array) / 4;
    int num = 7;

    printf("%d\n", qtdd_num(array, tamanho, num));

    return 0;
}