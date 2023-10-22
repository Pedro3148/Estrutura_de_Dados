## Estrutura de Dados

Aluno: Pedro Henrique Guedes de Almeida <br>
Universidade: Universidade Católica de Brasília (UCB) <br>
Linguagem usado no estudo: C
## Ementa

> A ementa do curso tem como foco estudar os seguintes tópicos:
* Arrays
* Listas Ligadas
* Pilhas
* Filas
* Hash
* Busca Binária e Linear
* Ordenação das estruturas
* Análise de Complexidade

## Array

> Estrutura Homogenia de dados

* Um array é uma coleção de dados do mesmo tipo como alocação Estática. 
* A alocação de cada elemento do array é dada de forma sequencial na memória "um atrás do outro".

## Algoritmos de Ordenação
A ordenação permite que o acesso ao dado seja mais eficiente
> Bubble Sort 
* O princípio de funcionamento desse algoritmo é a troca de valores em posições consecutivas

```
void swap(int *n1, int *n2){
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

void bubble_sort(int array[], int tamanho){
    int i, j;
    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - 1 - i; j++){
            if(array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}
```
* A função swap serve para trocar o valores das variáveis
* O swap dentro do if é executado quando a condição do array[j] ser maior que o elemento consecutivo do array, ou seja, array[j+1]
* O for mais interno "Empurra" o maior elemento fora de posição até a posição correta
* Sobre a condição do for mais interno: tamanho - 1 - i. O "- 1" garante que não ocorra a troca de valores com uma variavel fora do array. Além disso, o "- i" garante a eficiencia do algoritmo, uma vez que não é necessario fazer a comparação com os elementos já ordenados no final do array
* Tempo de execução é na ordem de O(N²)
* Visualização do <a href="https://www.youtube.com/watch?v=Cq7SMsQBEUw">algoritmo</a>
<hr>

> Selection Sort
* O princípio de funcionamento desse algoritmo é seleção do melhor elemento para ocupar aquela posição do array
```
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
```
* o laço mais interno busca o menor elemento do array a parti da posição i + 1
* ao final de sse laço ocorre o swap entre o posição "menor" e "i"
* Tempo de execução é na ordem de O(N²)
* É mais eficiente que o bubble sort
<hr>

> Insertion Sort