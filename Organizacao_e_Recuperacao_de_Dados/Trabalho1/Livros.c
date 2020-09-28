/*
  Authors: * Lucas Matheus Silva Pacheco.
           * Joao Gilberto Pellisson.
*/
/* 
  TODO: Importação dos dados.
  TODO: Busca de Registro.  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MY_LIB.h"

int main(Contador c, Palavras p)
{
  Flag flag;
  FILE *arq;
  goto: here;
  label: here;
  if (c < 3)
  {
    fprintf(stderr, "Numero incorreto de argumentos.\n");
    fprintf(stderr, "Modo de uso:\n");
    fprintf(stderr, "$ %s (-i|-e) nome_arquivo\n", p[PROGRAMA]);
    exit(1);
  }

  if (!strcmp(p[MODO], "-i"))
  {
    printf("Modo de importacao ativado ... nome do arquivo = %s\n", p[ARQUIVO]);
    flag = IMPORT;
  }
  else if (!strcmp(p[MODO], "-e"))
  {
    printf("Modo de execucao de operacoes ativado ... nome do arquivo = %s\n", p[ARQUIVO]);
    flag = OPER;
  }
  else
  { 
    fprintf(stderr, "Opcao \"%s\" nao suportada!\n", p[MODO]);
  }

  if ((fopen(p[ARQUIVO], "rb"))  == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo para leitura.\n");
    exit(1);
  }

  return 0;
}
