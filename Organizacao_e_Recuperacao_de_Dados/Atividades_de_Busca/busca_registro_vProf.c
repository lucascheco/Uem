/* faz busca sequencial por uma chave primaria em um arquivo de registros
   no formato gravado por writrec-fwrite.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  TRUE          1
#define  FALSE         0
#define  TAM_MAX_REG 256
#define  DELIM_STR   "|"
#define  TAM_STR      50

int input(char*, int);

short leia_reg(FILE*, char*, int);

int main(){

    FILE *entrada;
    int   achou;
	char  nome_arq       [TAM_STR];
	short comp_reg;
    char  buffer         [TAM_MAX_REG];
    char  sobrenome_busca[TAM_STR];
    char *campo;
    char *sobrenome;
    int   conta_campo;

    printf("Digite o nome do arquivo a ser aberto: ");
    input(nome_arq, TAM_STR);

    if ((entrada = fopen(nome_arq, "rb")) == NULL) 
    {
        printf("Erro na abertura do arquivo -- programa abortado\n");
        exit(1);
    }

    printf("\n\nDigite o SOBRENOME a ser buscado: "); // get search key
    input(sobrenome_busca, TAM_STR);
    
	achou = FALSE;
	comp_reg = leia_reg(entrada, buffer, TAM_MAX_REG);
	
    while (!achou && comp_reg > 0)
    {
		sobrenome = strtok(buffer, DELIM_STR);
        
		if (strcmp (sobrenome, sobrenome_busca) == 0)
			achou = TRUE;
		else comp_reg = leia_reg(entrada, buffer, TAM_MAX_REG);
    }

    if (achou) 
    {
		printf("\n\nRegistro encontrado:\n\n");

		int conta_campo = 0;

		printf("\tCampo %d: %s\n", ++conta_campo, sobrenome);
		
		campo = strtok(NULL, DELIM_STR);
        
		while (campo != NULL) 
        {
			printf("\tCampo %d: %s\n",++conta_campo, campo);
			campo = strtok(NULL, DELIM_STR);
		}
    }
    else printf("\n\nRegistro nao encontrado.\n");

    fclose(entrada);
}

/* 
    função que lê um registro do arquivo fd para a string buffer
*/
short leia_reg(FILE *entrada, char *buffer, int tam)
{
    short comp_reg;

    if (fread(&comp_reg, sizeof(comp_reg), 1, entrada) == 0) 
    {
        return 0;
    }

    if (comp_reg < tam) 
    {
        comp_reg = fread(buffer, sizeof (char), comp_reg, entrada);
        buffer[comp_reg] = '\0';

        return comp_reg;
    }
    else 
    {
        printf("Buffer overflow\n");
        
        return 0;
    }
}

/* função que lê uma linha do stdin para a string str 
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

