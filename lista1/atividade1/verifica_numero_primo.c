#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int i;
    int isPrime = 1;


    for(i=atoi(argv[1])-1;i>1;i--){
        if(atoi(argv[1]) % i == 0){
            isPrime = 0;
            break;
        }
    }

    if(atoi(argv[1]) == 1){
        isPrime = 0;
    }

    printf("%d\n", isPrime);

    return 0;
}