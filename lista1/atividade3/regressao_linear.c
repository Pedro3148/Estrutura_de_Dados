#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ponto {
    int x;
    float y;
};

void regressaoLinear(struct Ponto *pontos, int n);


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: %s <arquivo.csv>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    int numRegistros = 0;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numRegistros++;
    }

    struct Ponto *pontos = (struct Ponto *)malloc(numRegistros * sizeof(struct Ponto));
    if (pontos == NULL) {
        perror("Erro ao alocar memória");
        return 1;
    }

    fseek(arquivo, 0, SEEK_SET);

    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ",");
        pontos[i].x = atoi(token);
        token = strtok(NULL, ",");
        pontos[i].y = atof(token);
        i++;
    }

    fclose(arquivo);

    regressaoLinear(pontos, numRegistros);

    free(pontos);

    return 0;
}

void regressaoLinear(struct Ponto *pontos, int n) {
    int i;
    int somaX = 0;
    float somaY = 0;
    float somaXY = 0;
    int somaXQuadrado = 0;

    for (i = 0; i < n; i++) {
        somaX += pontos[i].x;
        somaY += pontos[i].y;
        somaXY += pontos[i].x * pontos[i].y;
        somaXQuadrado += pontos[i].x * pontos[i].x;
    }

    float mediaX = (float)somaX / n;
    float mediaY = somaY / n;

    float numerador = somaXY - n * mediaX * mediaY;
    float denominador = somaXQuadrado - n * mediaX * mediaX;
    float coeficienteAngular = numerador / denominador;

    float coeficienteLinear = mediaY - coeficienteAngular * mediaX;

    printf("y = %.2fx + %.2f\n", coeficienteAngular, coeficienteLinear);
}
