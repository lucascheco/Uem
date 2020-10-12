#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MY_LIB.h"

int modo(Flag flag, FILE *arq_source, FILE *arq_destination)
{
  if (flag == IMPORT)
  {
    importaArq_LED(arq_source, arq_destination);
    return flag;
  }
  else if(flag == OPER)
  {
    importaArq_OPR(arq_source, arq_destination);
    return flag;
  }
  else
  {
    return 0;
  }
}

int importaArq_LED(FILE *arq_source, FILE *arq_destination)
{
  char  c;            /* Para leitura de um caractere. */
  char *registro;     /* Tipo o buffer, uma string que guarda todos caracteres de um registro. */
  char *reallocError; /* Para error handling da função realloc. */
  short tamanho_Reg;  /* Tamanho do Registro que fica no comeco de cada um. */
  int   led = -1;     /* A led no no cabaçalho do arquivo. */
  int   cont = 0;     /* Será usado para aumentar blocos de memória no heap, conta quantos caracteres tem em cada registro.*/
  int   contPipe = 0; /* Variável para contar os pipes, vou importar de uma forma diferente. */ 
  

  registro = (char *)malloc(sizeof(char));
  
  /* Coloca a led no começo do arquivo. */
  fwrite(&led, sizeof(int), 1, arq_destination);

  while ((c = fgetc(arq_source)) != EOF)
  { 
    if(c == '|')
    {
      contPipe++;

      if(contPipe == 7) /* Como são 7 campos para cada registro, ao chegar aos */
      {
        registro[cont] = c;

        tamanho_Reg = (short)strlen(registro);

        fwrite(&tamanho_Reg, sizeof(short), 1, arq_destination);
        
        fwrite(registro, sizeof(char), tamanho_Reg, arq_destination);

        /* Zeramos as variaveis para leitura do próximo registro. */
        free(registro);
        
        registro = (char *)malloc(sizeof(char));

        contPipe = 0;
        cont = 0;

        fseek(arq_source, 1, SEEK_CUR);
        continue;
      }
    }
    
    registro[cont++] = c;
      
    if ((reallocError = (char *)realloc(registro, (cont + 1) * sizeof(char))) != NULL) /**/
    {
      registro = reallocError;
    }
  }

  free(registro);
  return cont;
}

int importaArq_OPR(FILE *arq_source, FILE *arq_oper)
{
  char  c;              /* Para leitura de um caractere. */
  char *chaveBuscaChar;
  int   chaveBuscaInt;  /* Transformei em int pra comparar com ==, sem usar a função strcmp */

  int   LED;
  short tam_Reg;
  short byte_off;       /* Armazena o byte offset para ler o próximo registro. */

  char *reallocError;
  char  c1;
  char *identificador = (char *)malloc(sizeof(char));
  int   ide_;           /* Para transformar o identificador em int para comparacao com do arquivo de operacoes. */
  int   cont = 0;

  while ((c = fgetc(arq_oper)) != EOF)
  {
    if (c == 'b')
    {
      chaveBuscaChar = busca(arq_oper);
      chaveBuscaInt  = atoi(chaveBuscaChar);

      // fread(&LED, sizeof(int), 1, arq_source);

      // while (1)
      // {
      //   fread(&tam_Reg, sizeof(short), 1, arq_source);
      //   byte_off = tam_Reg;

      //   while ((c1 = fgetc(arq_source)) != EOF) 
      //   {
      //     if (c1 == '|')
      //       break;

      //     identificador[cont++] = c1;

      //     if ((reallocError = (char *)realloc(identificador, (cont + 1) * sizeof(char))) != NULL) /**/
      //     {
      //       identificador = reallocError;
      //     }
      //   }  

      //   byte_off -= cont;

      //   cont = 0; /* Pra reutilizar essa variável. */

      //   if((ide_ = atoi(identificador)) == chaveBuscaInt)
      //   {
      //     fprintf(stdout, "\tCampo 1: %s\n", identificador);

      //     while (cont < 6)
      //     {
      //       fprintf(stdout, "\tCampo %d:", cont + 2);

      //       while ((c1 = fgetc(arq_source)) != '|')
      //         fprintf(stdout, "%c", c1);

      //       fprintf(stdout, "\n");

      //       cont++;
      //     }

      //     break;
      //   }
      //   else
      //   {
      //     if (feof(arq_source))
      //     {
      //       fprintf(stdout, "Nao encontrado.\n");
      //       break;
      //     }

      //     identificador = (char *)malloc(sizeof(char));
          
      //     fseek(arq_source, byte_off, SEEK_CUR);
      //   }
        
      // }

      printf("%d\n", chaveBuscaInt);
      free(chaveBuscaChar);
      // free(identificador);
      free(reallocError);

    }
    else if(c == 'r')
    {
      /* Funcao remove */

    }
    else if(c == 'i')
    {
      /* Funcao insere */

    }
  }
  return 0;
}

/* 
  Funcoes internas:
    * Busca
    * Remove
    * Insere

 */
char *busca(FILE *arq_oper)
{
  int   cont = 0;
  char *chave = (char *)malloc(sizeof(char));
  char *reallocError;
  char  c;

  fseek(arq_oper, 1, SEEK_CUR);

  while ((c = fgetc(arq_oper)) != EOF)
  {
    if (c == '\n')
      break;

    chave[cont++] = c;
      
    if ((reallocError = (char *)realloc(chave, (cont + 1) * sizeof(char))) != NULL) /**/
    {
      chave = reallocError;
    }
  }

  return chave;
}         

int remove_()
{

}

int insere()
{
  
}