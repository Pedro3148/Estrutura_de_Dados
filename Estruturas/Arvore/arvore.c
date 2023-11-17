#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Node *insert(Node *root, int data) {
    Node *temp = (Node *) malloc(sizeof(Node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL) {
        root = NULL;
    } else {
        Node *current = root;
        Node *parent = NULL;

        while(1){
            parent = current;
            if (data < parent->data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = temp;
                    return root;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = temp;
                    return root;
                }
            }
        }
    }

    return root;
}