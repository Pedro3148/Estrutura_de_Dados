typedef struct Objeto{
    char valor;
    struct Objeto *proximo_elemento;
} Objeto;

typedef struct Pilha{
    Objeto* topo;
    int quatidade_objetos;
} Pilha;

Pilha *init();
void push(Objeto *o, Pilha *p);
Objeto* pop(Pilha *p);