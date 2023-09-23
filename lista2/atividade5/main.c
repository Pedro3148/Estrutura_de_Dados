/*
Instruções
No seu repositório de atividades, crie uma pasta chamada atividade5 que contenha os arquivos main.c bubble_sort.h e bubble_sort.c;

O seu programa deve implementar o algoritmo bubble sort para ordenar um arquivo de palavras passados na chamada do programa e criar um arquivo com as palavras ordenadas como saída.
Exemplo:
./main arq_palavras.txt
Saída: arq_palavras_ordenado.txt

arq_palavras.txt
hoje
amanha
depois

arq_palavras_ordenado.txt
amanha
depois
hoje

OBS: o nome do arquivo é passado como argumento na chamada do programa (argv);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    int wordCount = 0;
    char word[100];  

    while (fscanf(inputFile, "%s", word) != EOF) {
        wordCount++;
    }

    fseek(inputFile, 0, SEEK_SET);

    char **words = (char **)malloc(wordCount * sizeof(char *));
    for (int i = 0; i < wordCount; i++) {
        words[i] = (char *)malloc(100 * sizeof(char));
        fscanf(inputFile, "%s", words[i]);
    }

    
    fclose(inputFile);

    bubbleSort(words, wordCount);

    char outputFile[1000];
    snprintf(outputFile, sizeof(outputFile), "%s_ordenado.txt", argv[1]);
    FILE *outputFilePtr = fopen(outputFile, "w");
    if (outputFilePtr == NULL) {
        perror("Erro ao criar o arquivo de saida");
        return 1;
    }

    for (int i = 0; i < wordCount; i++) {
        fprintf(outputFilePtr, "%s\n", words[i]);
    }

    fclose(outputFilePtr);

    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}