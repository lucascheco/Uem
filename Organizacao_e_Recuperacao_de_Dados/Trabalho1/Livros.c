/*
  Authors: * Lucas Matheus Silva Pacheco.
           * Joao Gilberto Pellisson.
*/
/* 
  DONE: Importação dos dados. 
  TODO: Busca de Registro por indentificador.  
  TODO: Inserção de novo registro.
  TODO: Remoção de Registro.
  Obs: Nao posso importar tudo como char, importar registro com cada campo no seu respectivo tipo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MY_LIB.h"

int main(Contador c, Argumentos p)
{
  Flag flag;
  FILE *arq_s, *arq_d, *arq_oper;

/* Error handling */
  if (c < 3)
  {
    fprintf(stderr, "Numero incorreto de argumentos.\n");
    fprintf(stderr, "Modo de uso:\n");
    fprintf(stderr, "$ %s (-i|-e) nome_arquivo\n", p[PROGRAMA]);
    exit(1);
  }

/*------------------------------------------------------------------------------------------------*/
  /* Captura se é importação ou operações. */
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
    exit(1);
  }

/*------------------------------------------------------------------------------------------------*/
/* Seleciona o modo.                                                                              */
/*------------------------------------------------------------------------------------------------*/
/* Modo importação. */
  if(flag == IMPORT)
  {
    /* Abre o arquivo de registros de livros. */
    if ((arq_s = fopen(p[ARQUIVO], "rb")) == NULL)
    {
      fprintf(stderr, "Erro ao abrir arquivo para leitura.\n");
      exit(1);
    }
    
    /* Para copiar o arquivo de livros, mas organizado em LED, ou abre um ja existente. */
    if ((arq_d = fopen("livros.dat", "wb")) == NULL)
    {
      fprintf(stderr, "Erro ao abrir arquivo para escrita.\n");
      exit(1);
    }

    if(!modo(flag, arq_s, arq_d))
    {
      fprintf(stderr, "Erro ao executar a importacao para um arquivo \".dat.\"\n");
      exit(1);
    }

    fclose(arq_s);
    fclose(arq_d);
  }

/* Modo Operação. */
  if(flag == OPER)
  {
    /* Abre o arquivo de operações */
    if ((arq_oper = fopen(p[ARQUIVO], "rb")) == NULL)
    {
      fprintf(stderr, "Erro ao abrir arquivo para leitura.\n");
      exit(1);
    }

    /* Para copiar o arquivo de livros, mas organizado em LED, ou abre um ja existente. */
    if ((arq_d = fopen("livros.dat", "rb")) == NULL)
    {
      fprintf(stderr, "Erro ao abrir arquivo para leitura.\n");
      exit(1);
    }

    if(!modo(flag, arq_s, arq_oper))
    {
      fprintf(stderr, "Erro ao executar a importacao para um arquivo \".dat.\"\n");
      exit(1);
    }

    fclose(arq_d);
    fclose(arq_oper);
  }

  return 0;
}
