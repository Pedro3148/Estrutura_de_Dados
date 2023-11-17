typedef struct Node {
    int data;

    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int data);