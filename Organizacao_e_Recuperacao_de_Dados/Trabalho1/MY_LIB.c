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

int 