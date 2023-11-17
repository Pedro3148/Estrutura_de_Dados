#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int validar_exp(char *exp) {
    Stack *stack = create_stack();
    int i;
    int isValid = 1;

    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(')
            push(stack, create_node('x', NULL));
        else if (exp[i] == ')') 
            if (amount_stack(stack) == 0)
                isValid = 0;
            else
                pop(stack);
        else 
            isValid = 0;
    }

    if (amount_stack(stack))
        isValid = 0;
    
    free(stack);
    return isValid;
}

int main() {
    printf("valido: %d\n", validar_exp("(((())))(((())))"));
    return 0;
}
