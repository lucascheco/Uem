/*
    Author: Lucas Matheus Silva Pacheco
    RA:     112-686
    Date:   30/08/2020

    Description:
        * Read data from a binary file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int le_registro(FILE *arq, char *buffer);

int main()
{
    FILE *NOME_ARQ;
    int   comprimento_Registro, 
          i = 1, j = 1;

    char *buffer = (char *)malloc(180 * sizeof(char));
    char *campo  = (char *)malloc(30  * sizeof(char));
    
    if ((NOME_ARQ = fopen("SAIDA2.txt", "rb")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    } 

    comprimento_Registro = le_registro(NOME_ARQ, buffer);

    while (comprimento_Registro > 0)
    {
        i = 1;
        campo = strtok(buffer, "|");
        
        fprintf(stdout, "Registro #%d\n", j);
        
        while (campo != NULL)
        {
            fprintf(stdout, "\tcampo #%d: %s\n", i, campo);
            campo = strtok(NULL, "|");
            i++;
        }

        comprimento_Registro = le_registro(NOME_ARQ, buffer);

        j++;
    }

    free(buffer);
    fclose(NOME_ARQ);

    return 0;
}

int le_registro(FILE *arq, char *buffer)
{
    int comprimento_registro;

    fread(&comprimento_registro, 180, 1, arq);

    if (!feof(arq))
        return 0;

    if (comprimento_registro < 180)
    {
        fread(buffer, comprimento_registro, 1, arq);

        buffer[179] = '\0';
        
        return comprimento_registro;
    }
    else
    {
        return 0;
    }
    
}
