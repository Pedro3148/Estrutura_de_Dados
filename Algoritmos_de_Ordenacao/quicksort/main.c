#include <stdio.h>
#include "quick_sort.h"

void mostrar(int *a, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int array[] = {
        4, 5, 9, 1, 7, 2, 3
    };

    particiona(array, 0, 6);
    mostrar(array, 7);

    return 0;
}
