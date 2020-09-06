/*
    Author: Lucas Matheus Silva Pacheco
    RA:     112-686
    Date:   30/08/2020

    Description:
        * Read data from a file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int le_campo(FILE *arq, char *str);

int main()
{
    FILE *NOME_ARQ;
    int comprimento_campo, i = 1;

    char *str = (char *)malloc(30 * sizeof(char));

    if ((NOME_ARQ = fopen("SAIDA.txt", "r")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    } 

    comprimento_campo = le_campo(NOME_ARQ, str);

    while (comprimento_campo > 0)
    {
        fprintf(stdout, "campo #%3d: %s\n", i, str); 

        comprimento_campo = le_campo(NOME_ARQ, str);
        i++;
    }

    free(str);
    fclose(NOME_ARQ);

    return 0;
}

int le_campo(FILE *arq, char *str)
{
    int i = 0;
    char ch = fgetc(arq);

    while (ch != EOF && ch != '|')
    {
        str[i] = ch;
        i++;
        ch = fgetc(arq);
    }

    str[i] = '\0';

    return i;
}