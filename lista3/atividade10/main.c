#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tabela_hash.h"


int main(int argc, char* argv[]) {
     char **tabela = tabela_hash();

     // inserindo elementos na tabela hash
     put("Brasil", "Brasilia", tabela);
     put("Argentina", "Buenos Aires", tabela);
     put("Equador", "Quito", tabela);
     put("Paraguai", "Asuncion", tabela);
     put("Peru", "Lima", tabela);
     put("Venezuela", "Caracas", tabela);

     // Mostrando os elementos da tabela hash
     printf("Chave: Brasil => %s\n", get("Brasil", tabela));
     printf("Chave: Argentina => %s\n", get("Argentina", tabela));
     printf("Chave: Equador => %s\n", get("Equador", tabela));
     printf("Chave: Paraguai => %s\n", get("Paraguai", tabela));
     printf("Chave: Peru => %s\n", get("Peru", tabela));
     printf("Chave: Venezuela => %s\n", get("Venezuela", tabela));

     // Verficando se a tabela contem o elemento com a chave Equador
     if (contains("Equador", tabela)) {
          printf("O elemento com a chave Equador esta contido na tabela\n");
     } else {
          printf("O elemento com a chave Equador nao esta contido na tabela\n");
     }

     // Removendo o elemento Brasil da tabela Hash
     remove_elemento("Brasil", tabela);
     printf("Chave: Brasil => %s\n", get("Brasil", tabela));
     return 0;
}