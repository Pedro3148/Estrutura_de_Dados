/*
Exercício 3 - Verificar se um elemento existe no array Escreva uma função que recebe um array de strings e uma string de busca, e retorna "1" se a string de busca existe no array, ou "0" caso não exista.

Exemplo: busca_string(["texto", "J", "EDA"], "EDO")
Saída: 0 
*/

#include <stdio.h>
#include <string.h>

int busca_string(char **array, int tamanho, char *string_busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], string_busca) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char *array[] = {"texto", "J", "EDA"};
    char *string_busca;
    int tamanho = sizeof(array) / sizeof(array[0]);

    gets(string_busca);
    int resultado = busca_string(array, tamanho, string_busca);

    if (resultado == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
