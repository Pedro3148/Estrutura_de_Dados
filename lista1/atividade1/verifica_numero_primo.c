#include <stdio.h>
#include <stdlib.h>

void prime(int value){
    int i;
    int isPrime = 1;

    if(value == 1){
        isPrime = 0;
    }

    for(i=value-1;i>1;i--){
        if(value % i == 0){
            isPrime = 0;
            break;
        }
    }

    printf("%d\n", isPrime);

    return;
}

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Erro de Sintaxe no arquivo %s", argv[0]);
        exit(1);
    }

    prime(atoi(argv[1]));

    return 0;
}