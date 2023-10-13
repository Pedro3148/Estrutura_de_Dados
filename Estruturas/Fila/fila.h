typedef struct ELEMENTO {
    int valor;
    struct ELEMENTO *proximo;
} ELEMENTO;

typedef struct FILA {
    int qtd_elemento;
    ELEMENTO *inicio;
    ELEMENTO *final;
} FILA;

FILA *criar_fila();
int tamanho_fila(FILA*);
void inserir_fila(FILA*, ELEMENTO*);
ELEMENTO *remove_fila(FILA*);
