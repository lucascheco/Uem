/* 
    programa que abre ou cria um arquivo de registros de tamanho fixo.
    Os registros podem ser adicionados ou modificados.
    Registros a serem modificados sao buscados por RRN 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// CONSTANTES
#define TAM_STR     50
#define TAM_MAX_REG 64
#define DELIM_STR   "|"
                      
// GLOBAIS
struct 
{
    int cont_reg;
} cabecalho; // header do arquivo - 4 bytes

FILE *arq;

// INTERFACES
int   menu();
void  le_info_reg(char*);
int   le_rrn();
void  le_e_mostra();
int   modifica();
void  concatena_buffer(char*, char*);
int   input(char*, int);

// IMPLEMENTACOES
int main()
{
    int  i, opcao, rrn;
    int  byte_offset;
    char nome_arq[TAM_STR];
    char buffer  [TAM_MAX_REG + 1];

    printf("Digite o nome do arquivo: ");
    input(nome_arq, TAM_STR);
    
    if ((arq = fopen(nome_arq,"r+b")) == NULL) 
    {
       arq = fopen(nome_arq, "w+b");

       cabecalho.cont_reg = 0;

       fwrite(&cabecalho, sizeof(cabecalho), 1, arq);
    }
    else
        fread(&cabecalho, sizeof(cabecalho), 1, arq);

    while ((opcao = menu()) < 3)
    {
          switch(opcao)
          {
             case 1: //insercao
                  printf("Digite os dados para o novo registro\n\n");
                  le_info_reg(buffer);

                  byte_offset = cabecalho.cont_reg * TAM_MAX_REG + sizeof(cabecalho);
                  
                  fseek(arq, (long) byte_offset, SEEK_SET);
                  
                  fwrite(buffer, sizeof(char), TAM_MAX_REG, arq);
                  
                  cabecalho.cont_reg++;
                  
                  break;

             case 2: //busca e alteracao
                  rrn = le_rrn();

                  if (rrn >= cabecalho.cont_reg)
                  {
                     printf("O RRN eh muito grande");
                     printf("... retornando ao menu ...");
                     
                     break;
                  }

                  byte_offset = rrn * TAM_MAX_REG + sizeof(cabecalho);
                  fseek(arq, (long) byte_offset, SEEK_SET);

                  le_e_mostra();

                  if (modifica())
                  {
                    printf("\n\nDigite os novos dados do registro: \n\n");
                    le_info_reg(buffer);
                    
                    fseek(arq, (long) byte_offset, SEEK_SET);
                    
                    fwrite(buffer, sizeof(char), TAM_MAX_REG, arq);
                  }
                  break;
          } // end switch
    }// end while

    rewind(arq);
    fwrite(&cabecalho, sizeof(cabecalho), 1, arq);

    fclose(arq);
}// end main


int menu()
{
	 char opcao[TAM_STR];

     printf("\n\n\n\n\t PROGRAMA PARA INSERCAO E ALTERACAO DE REGISTROS\n");
     printf("\n\nSuas opcoes sao:\n\n");
     printf("\t1. Inserir um novo registro\n");
     printf("\t2. Buscar um registro por RRN para alteracoes\n");
     printf("\t3. Terminar o programa\n\n");
     printf("Digite o numero da sua escolha: ");
     input(opcao, TAM_STR);
     
     return(atoi(opcao));

} // end menu


int le_rrn()
{
    char rrn[TAM_STR];

    printf("\n\nDigite o RRN do registro: ");
    input(rrn, TAM_STR);
    
    return(atoi(rrn));
}

int modifica()
{
    char resposta[TAM_STR];

    printf("\n\nVoce quer modificar este registro?\n");
    printf("    Responda S ou N, seguido de <ENTER> ==>");
    input(resposta, TAM_STR);

    return((resposta[0] == 'S') || (resposta[0] == 's') ? 1 : 0);
}

/* 
    Atenção! Esta função não é segura, pois deixa que o usuário
    informe campos que, juntos, ultrapassem a capacidade do registro.
    Você pode arrumar isso se desejar...     
*/
void le_info_reg(char *buffer)
{
     char *prompt[] = {
        "    Sobrenome: ",
        "Primeiro nome: ",
        "     Endereco: ",
        "       Cidade: ",
        "       Estado: ",
        "          CEP: ",
        ""
     };
     int i;
     char campo[TAM_STR];

     buffer[0] = '\0';

     for (i = 0; prompt[i] != ""; i++)
     {
         printf("%s", prompt[i]);
         input(campo, TAM_STR);

         concatena_buffer(buffer,campo);
     }
}


void le_e_mostra()
{
    char  buffer[TAM_MAX_REG+1];
    char *campo;

    fread(buffer, sizeof(char), TAM_MAX_REG, arq);
    buffer[TAM_MAX_REG] = '\0';

    printf("\n\nConteudo do registro\n");
	campo = strtok(buffer, DELIM_STR);
	 
	while (campo != NULL) 
    {
	    printf("\t%s\n",campo);
		campo = strtok(NULL, DELIM_STR);
	}
}


/* 
    funcao que adiciona ao buffer a string campo e o delimitador "|"
*/
void concatena_buffer(char *buffer, char *campo)
{
	strcat(buffer, campo); 
    strcat(buffer, DELIM_STR);
}

/* 
    funcao que le uma linha do stdin para a string str 
*/
int input(char * str, int size) 
{    
    int i = 0;    
    char c = getchar();

    while (c != '\n') 
    {        
        if (size > 1) 
        {            
            str[i] = c;            
            i++;            
            size--;        
        }        
        c = getchar();   
    }    
    str[i] = '\0';    
    return i;
}

/* Converte o char ci para UPPERCASE e retorna em co */
char maiuscula(char ci)
{
     char co = (ci >= 'a' && ci <= 'z') ? ci & 0x5f : ci;
     return co;
}