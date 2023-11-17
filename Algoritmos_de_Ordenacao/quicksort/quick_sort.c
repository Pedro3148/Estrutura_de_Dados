// usa a recursividade para adotar a estrategia de dividir para conquistar
// primeiro é selecionado um pivot que consistem em um elemento do array
// depois o array é organizado de forma que os elemento menores que o pivot fiquem a esquerda e os maiores a direita
// o processo recursivo se repete até chegar que partição tenha apenas um elemento
// duas funções: 
// primeira função chamada partição se encarrega de particionar o array
// segunda função chamada quick sort se encarrega de gerir a particão do array, verifica se o array contem de um elemento, calcula o valor correspondente do pivot e chama a si mesmo
#include "quick_sort.h"

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int particiona(int *array, int left, int right) {
    int pointer_left = left, pointer_right = right;
    int pivot = left;
    
    while (pointer_left < pointer_right) {
        while (array[pointer_left] <= array[pivot] && pointer_left < right) {
            pointer_left++;
        }

        while (array[pointer_right] > array[pivot] && pointer_right >= left) {
            pointer_right--;
        }

        if (pointer_left < pointer_right) {
            swap(&array[pointer_left], &array[pointer_right]);
        }
    }
    return 1
}
