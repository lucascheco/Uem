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
  int   LED = -1;     /* A led no no cabaçalho do arquivo. */
  int   cont = 0;     /* Será usado para aumentar blocos de memória no heap, conta quantos caracteres tem em cada registro.*/
  int   contPipe = 0; /* Variável para contar os pipes, vou importar de uma forma diferente. */ 
  

  registro = (char *)malloc(sizeof(char));
  
  /* Coloca a led no começo do arquivo. */
  fwrite(&LED, sizeof(int), 1, arq_destination);

  while ((c = fgetc(arq_source)) != EOF)
  { 
    if(c == '|')
    {
      contPipe++;

      if(contPipe == 7) /* Como são 7 campos para cada registro, ao chegar aos */
      {
        registro[cont] = c;

        tamanho_Reg = (short)cont + 1;

        fwrite(&tamanho_Reg, sizeof(short), 1, arq_destination);
        
        fwrite(registro, sizeof(char), tamanho_Reg, arq_destination);

        /* Zeramos as variaveis para leitura do próximo registro. */
        
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
  int   tam_insere_Reg;   /* Tamanho do registro a ser inserido. */

  fprintf(stdout, "\n");

  while ((c = fgetc(arq_oper)) != EOF)
  {
    /* Busca e printa a chave no stdout. */
    if (c == 'b')
    {
      chaveBuscaChar = le_Chave(arq_oper);
      chaveBuscaInt  = atoi(chaveBuscaChar);

      busca(arq_source, chaveBuscaInt);
    }
    
    /* Remove o registro. */
    else if(c == 'r')
    {
      chaveBuscaChar = le_Chave(arq_oper);
      chaveBuscaInt  = atoi(chaveBuscaChar);

      if(remove_(arq_source, chaveBuscaInt))
      {
        fprintf(stdout, "Posicao: ofsset = %d bytes\n\n", leLED(arq_source));
      }

    }
    
    /* Insere um novo registro. */
    else if(c == 'i')
    {
      /* Funcao insere */
      fprintf(stdout, "Funcao insere.\n");
      chaveBuscaChar = le_Chave(arq_oper); /* Nesse caso chaveBuscachar é o novo registro. */
      
      fprintf(stdout, "*INSERCAO* do registro de chave\" \" (%ld bytes)\n", strlen(chaveBuscaChar));
      insere(arq_source, chaveBuscaChar);
    }
  }

  if(feof(arq_oper))
    exit(1);
    
  free(chaveBuscaChar);

  return 0;
}

/* 
  Funcoes internas:
    * Busca
    * Remove
    * Insere

 */
char *le_Chave(FILE *arq_oper)
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

int busca(FILE *arq_source, int chaveBuscaInt)
{
  int   LED;
  short tam_Reg = 0;
  short byte_off = 0;       /* Armazena o byte offset para ler o próximo registro. */

  char *reallocError;
  char  c1;
  char *identificador = (char *)malloc(sizeof(char));
  int   ide_;           /* Para transformar o identificador em int para comparacao com do arquivo de operacoes. */
  int   cont = 0;

  fprintf(stdout, "*BUSCA* pelo registro de chave \"%d\"\n", chaveBuscaInt);
        
  fread(&LED, sizeof(int), 1, arq_source);  


  while (1)
  {
    fread(&tam_Reg, sizeof(short), 1, arq_source);

    while ((c1 = fgetc(arq_source)) != EOF) 
    {
      if (c1 == '*')
      {
        fseek(arq_source, tam_Reg - 1, SEEK_CUR);
        break;
      }

      if (c1 == '|')
        break;

      identificador[cont++] = c1;
      
      if ((reallocError = (char *)realloc(identificador, (cont + 1) * sizeof(char))) != NULL) /**/
      {
        identificador = reallocError;
      }
    }  

    if (c1 == '*')
    {
      cont = 0;
      continue;
    }

    cont++;

    if((ide_ = atoi(identificador)) == chaveBuscaInt)
    {
      fseek(arq_source, -cont, SEEK_CUR); 

      mostra_Reg(arq_source, tam_Reg);

      cont = 0;

      identificador = (char *)malloc(sizeof(char));
      rewind(arq_source);
      break;
    }
    else
    {
      if (c1 == EOF)
      {
        fprintf(stdout, "erro: registro nao encontrado!\n\n");
        
        cont = 0;
        identificador = (char *)malloc(sizeof(char));
        rewind(arq_source);
        break;
      }

      identificador = (char *)malloc(sizeof(char));
      fseek(arq_source, -cont, SEEK_CUR);   /* Retorna o seek cont bytes, pois é o tamanho do primeiro campo. */

      fseek(arq_source, tam_Reg, SEEK_CUR); /* Avança o seek para a leitura do próximo registro. */
      cont = 0;
    }
    
  }
  
  free(reallocError);
  free(identificador);

  return 0;
}

int remove_(FILE *arq_source, int chaveBuscaInt)
{
  int boolean;
  int   LED;
  short tam_Reg = 0;
  int   byte_off = 0;  

  char *reallocError;
  char  c1;
  char *identificador = (char *)malloc(sizeof(char));
  int   ide_;           /* Para transformar o identificador em int para comparacao com do arquivo de operacoes. */
  int   cont = 0;

  char remov = '*';

  fprintf(stdout, "*REMOCAO* do registro de chave \"%d\"\n", chaveBuscaInt);
        
  fread(&LED, sizeof(int), 1, arq_source);  
  byte_off += (int)sizeof(int);

  while (1)
  {
    fread(&tam_Reg, sizeof(short), 1, arq_source);
 
    while ((c1 = fgetc(arq_source)) != EOF) 
    {
      if (c1 == '*')
      {
        byte_off += (int)tam_Reg;
        byte_off += (int)sizeof(short);
        fseek(arq_source, tam_Reg - 1, SEEK_CUR);
        break;
      }

      if (c1 == '|')
        break;

      identificador[cont++] = c1;

      if ((reallocError = (char *)realloc(identificador, (cont + 1) * sizeof(char))) != NULL) /**/
      {
        identificador = reallocError;
      }
    }  
    
    if (c1 == '*')
    {
      cont = 0;
      identificador = (char *)malloc(sizeof(char));
      continue;
    }

    cont++;

    if((ide_ = atoi(identificador)) == chaveBuscaInt)
    {
      fprintf(stdout, "Registro removido! (%d bytes)\n", tam_Reg);
      fseek(arq_source, -cont, SEEK_CUR); 

      fwrite(&remov,    sizeof(char), 1, arq_source);
      fwrite(&LED,      sizeof(int),  1, arq_source);

      cont = 0;
      identificador = (char *)malloc(sizeof(char));

      rewind(arq_source);
      fwrite(&byte_off, sizeof(int),  1, arq_source);

      byte_off = 0;
      rewind(arq_source);

      boolean = Verdadeiro;
      break;
    }
    else
    {
      if (c1 == EOF)
      {
        fprintf(stdout, "erro: registro nao encontrado!\n\n");
        
        cont = 0;
        byte_off = 0;
        identificador = (char *)malloc(sizeof(char));
        rewind(arq_source);

        boolean = Falso;
        break;
      }

      byte_off += (int)tam_Reg;
      byte_off += (int)sizeof(short);

      identificador = (char *)malloc(sizeof(char));
      
      fseek(arq_source, -cont, SEEK_CUR);   /* Retorna o seek cont bytes, pois é o tamanho do primeiro campo. */
      fseek(arq_source, tam_Reg, SEEK_CUR); /* Avança o seek para a leitura do próximo registro. */
      cont = 0;
    }
    
  }
  
  free(reallocError);
  free(identificador);

  return boolean;
}

int insere(FILE *arq_source, char *chaveBuscaChar)
{
  int   LED      = -2;
  int   prox_LED = -2;
  int   ante_LED = -2;
  int   nova_LED;

  short tam_Reg_Inserir = (short)strlen(chaveBuscaChar);
  short tam_Reg_Disponivel;
  short sobra = 0;

  char  remov = '*';
  
  fread(&LED, sizeof(int), 1, arq_source);

  fseek(arq_source, LED - sizeof(int), SEEK_CUR); /* Vai para o primeiro espaco disponivel. */

  prox_LED = LED;
  while (1)
  {
    ante_LED = prox_LED;

    fread(&tam_Reg_Disponivel, sizeof(short), 1, arq_source);
    fseek(arq_source, 1, SEEK_CUR);                 /* Pula o '*' .*/
    fread(&prox_LED, sizeof(int), 1, arq_source);   /* Le o proximo byteoffset disponivel. */


    if(tam_Reg_Disponivel >= tam_Reg_Inserir)
    {
      sobra = tam_Reg_Disponivel - tam_Reg_Inserir - 2;

      fseek(arq_source, -(sizeof(short) + sizeof(int) + sizeof(char)), SEEK_CUR); /* Retorna o seek para o comeco do registro. */
      


      if (sobra > 50)
      {
        fwrite(&tam_Reg_Inserir, sizeof(short), 1,               arq_source);
        fwrite( chaveBuscaChar,  sizeof(char),  tam_Reg_Inserir, arq_source);

        fprintf(stdout, "Local: ofsset = %d\n", ante_LED);
        fprintf(stdout, "Tamanho do espaço: %d\n", tam_Reg_Disponivel);
        
        fwrite(&sobra,    sizeof(short), 1, arq_source);
        fwrite(&remov,    sizeof(char),  1, arq_source);
        fwrite(&prox_LED, sizeof(int),   1, arq_source);
        rewind(arq_source);
        
        nova_LED = LED + (int)tam_Reg_Inserir;

        fwrite(&nova_LED, sizeof(int), 1, arq_source);

        rewind(arq_source);

        fprintf(stdout, "Tamanho da sobra: %d\n", sobra);
        fprintf(stdout, "Offset da sobra: %d\n\n", ante_LED + tam_Reg_Inserir + 2);
      }
      else
      {
        fwrite(&tam_Reg_Disponivel, sizeof(short), 1,               arq_source);
        fwrite( chaveBuscaChar,     sizeof(char),  tam_Reg_Inserir, arq_source);

        fprintf(stdout, "Local: ofsset = %d\n", ante_LED);
        fprintf(stdout, "Tamanho do espaço: %d\n", tam_Reg_Disponivel);
        nova_LED = prox_LED;

        rewind(arq_source);

        fwrite(&nova_LED, sizeof(int), 1, arq_source);

        rewind(arq_source);
        fprintf(stdout, "Warning: Fragmentação.\n");
      }
      break;
    }
    else /* Se o tamanho nao for adequado */
    {
      ante_LED = prox_LED;
      fseek(arq_source, prox_LED, SEEK_SET);
      
      if (prox_LED == -1)
      {
        fseek(arq_source, 0, SEEK_END);
        fwrite(&tam_Reg_Inserir, sizeof(short), 1,               arq_source);
        fwrite( chaveBuscaChar,  sizeof(char),  tam_Reg_Inserir, arq_source);
        rewind(arq_source);
        break;
      }
    }
  } 
  return 0;
}

/*--------------------------------------------------------------------*/
void mostra_Reg(FILE *arq_source, int tam_Reg)
{
  int cont = 0;
  char c1;
  fprintf(stdout, "===>\t\n");
  while (cont < tam_Reg)
  {
    c1 = fgetc(arq_source);
    fprintf(stdout, "%c", c1);
    cont++;
  }
  fprintf(stdout, " (%d) bytes", tam_Reg);
  fprintf(stdout, "\n===>");
  fprintf(stdout, "\n\n\n");
      
}

int leLED(FILE *arq_source)
{
  int LED;

  fread(&LED, sizeof(int), 1, arq_source);
  rewind(arq_source);

  return LED;
}