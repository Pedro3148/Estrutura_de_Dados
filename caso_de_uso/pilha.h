typedef struct Stack {
    int amount;
    struct Node *top;
} Stack;

typedef struct Node {
    char value;
    struct Node *next;
} Node;

Stack *create_stack();
Node *create_node(char value, Node *next);
void push(Stack *stack, Node *node);
Node *pop(Stack *stack);
int amount_stack(Stack *stack);
void print_stack(Stack *stack);