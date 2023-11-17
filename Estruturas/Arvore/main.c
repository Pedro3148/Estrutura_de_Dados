#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void printTree(Node* root, int nivel) {
    if (root != NULL) {
        printTree(root->right, nivel + 1); // Imprime a subárvore direita primeiro

        for (int i = 0; i < nivel; i++) {
            printf("   ");
        }

        printf("*-- %d\n", root->data); // Imprime o nó atual

        printTree(root->left, nivel + 1); // Imprime a subárvore esquerda por último
    }
}

int main(int argc, char *argv[]) {
    int i;
    int array[] = {
        1, 5, 3, 7, 2, 8, 5
    };
    int size = sizeof(array) / sizeof(int);

    Node *root = NULL;
    for (i = 0; i < size; i++) {
        root = insert(root, array[i]);
    }
    
    printTree(root, 0);

    return 0;
}
