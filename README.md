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

> Merge Sort
* o princípio de funcionamento desse algoritmo é a recursão para dividir o array em unidades menores e depois entra o merge. O merge é a união de forma ordenada de dois dos segmentos do array. 

```
void merge(int *v, int left, int middle, int right) {
    int indexVetor1, indexVetor2, indexHelper;
    indexVetor1 = left;
    indexVetor2 = middle + 1;

    int length = right - left + 1;
    int *helper = (int *) calloc(length, sizeof(int));

    if (helper) {
        for (indexHelper = 0; indexHelper < length; indexHelper++) {
            if (indexVetor1 <= middle && indexVetor2 <= right) {
                if (v[indexVetor1] < v[indexVetor2]) {
                    helper[indexHelper] = v[indexVetor1];
                    indexVetor1++;
                } else {
                    helper[indexHelper] = v[indexVetor2];
                    indexVetor2++;
                }
            } else {
                if (indexVetor1 <= middle) {
                    helper[indexHelper] = v[indexVetor1];
                    indexVetor1++;
                } else {
                    helper[indexHelper] = v[indexVetor2];
                    indexVetor2++;
                }
            }
        }
        int i = left;
        for (indexHelper = 0; indexHelper < length; indexHelper++) {
            v[i] = helper[indexHelper];
            i++;
        }
    }
    free(helper);
}

void merge_sort(int *v, int left, int right) {
    int middle;
    if (left < right) {
        middle = (left + right) / 2;
        merge_sort(v, left, middle);
        merge_sort(v, middle + 1, right);
        merge(v, left, middle, right);
    }
}
```
* merge_sort: consiste em uma chamada recursiva que divide o array por indece: left, middle e right, assim formando uma especie de nova array
* merge: união de segmentos do array de forma ordenada
* usa um array Helper como array temporário para ajudar na ordenação
* usando variaveis de controle que sempre começam no inicio do "array" correspondete faça um loop que preenche o Helper com elemento dois dois arrays, comparando elemento de um segmento com o outro segmento e depositando o menor no helper
* Por fim, passa todos os elementos do helper para o array original
* Embora o eficiencia desse algoritmo seja a mesma independente da ordem, ele possui um gasto elevado de espaço memoria comparado aos outros algoritmos de ordenação

>Quick Sort
