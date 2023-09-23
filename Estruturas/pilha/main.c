#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char *argv[]) {
    Objeto o1;
    o1.valor = 'a';
    Objeto o2;
    o2.valor = 'b';
    Objeto o3;
    o3.valor = 'c';
    Pilha *P = init();

    push(&o1, P);
    push(&o2, P);
    push(&o3, P);
    
    Objeto *o;
    do{
        o = pop(P);
        if (o != NULL){
            printf("%c\n", o->valor);
        }
    } while (o != NULL);

    return 0;
}
