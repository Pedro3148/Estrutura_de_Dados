#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Stack *create_stack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack != NULL) {
        stack->amount = 0;
        stack->top = NULL;
    }
    return stack;
}

Node *create_node(char value, Node *next) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node != NULL) {
        node->value = value;
        node->next = next;
    }
    return node;
}

void push(Stack *stack, Node *node) {
    if (stack == NULL) return;
    if (node == NULL) return;

    if (stack->top != NULL)
        node->next = stack->top;
    else
        node->next = NULL;

    stack->top = node;
    stack->amount++;
}

Node *pop(Stack *stack) {
    if (stack->top == NULL) return NULL;

    Node *node = stack->top;
    stack->top = node->next;
    stack->amount--;
    return node;
}

int amount_stack(Stack *stack) {
    return stack->amount;
}

void print_stack(Stack *stack) {
    if (stack == NULL) return;

    Node *node = stack->top;
    while (node != NULL) {
        printf("%c ", node->value);
        node = node->next;
    }
}