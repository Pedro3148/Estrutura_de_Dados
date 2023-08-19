/*
Exercício 3 - Verificar se um elemento existe no array Escreva uma função que recebe um array de strings e uma string de busca, e retorna "1" se a string de busca existe no array, ou "0" caso não exista.

Exemplo: busca_string(["texto", "J", "EDA"], "EDO")
Saída: 0 
*/

#include <stdio.h>


int main(){

    char string[10][10] = {
        {"texto"}, {"J"}, {"EDA"}
    };

    printf("%d", sizeof(string));
    
    return 0;
}