#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_MAX_REG 256
#define DELIM_STR "|"
#define TAM_STR 50

int input(char * str, int size);

short leia_reg(FILE *entrada, char * buffer, int tam);

int main()
{
    FILE *entrada;
    char  nome_arq[TAM_STR];
    char  buffer  [TAM_MAX_REG];
    short comp_reg;
    int   conta_reg, conta_campo;
    char *campo;

    printf("Digite o nome do arquivo a ser aberto: ");
    input(nome_arq, TAM_STR);

    if ((entrada = fopen(nome_arq, "rb")) == NULL) 
    {
        printf("Erro na abertura do arquivo -- programa abortado\n");
        exit(1);
    }

    conta_reg = 0;
    comp_reg  = leia_reg(entrada, buffer, TAM_MAX_REG);

    while (comp_reg > 0)  
    {
        printf("Registro %d\n", ++conta_reg);

        conta_campo = 0;

        campo = strtok(buffer, DELIM_STR);

        while (campo != NULL)
        {
            printf("\tCampo %d: %s\n", ++conta_campo, campo);
            campo = strtok(NULL, DELIM_STR);
        }

        printf("\n");

        comp_reg = leia_reg(entrada, buffer, TAM_MAX_REG);
    }

    fclose(entrada);

    return 0;
}

short leia_reg(FILE *entrada, char * buffer, int tam)
{
    short comp_reg;

    if (fread(&comp_reg, sizeof(comp_reg), 1, entrada) == 0) 
        return 0;

    if (comp_reg < tam) 
    {
        comp_reg = fread(buffer, sizeof(char), comp_reg, entrada);
        
        buffer[comp_reg] = '\0';

        return comp_reg;
    }
    else 
    {
        printf("Buffer overflow\n");
        
        return 0;
    }
}

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