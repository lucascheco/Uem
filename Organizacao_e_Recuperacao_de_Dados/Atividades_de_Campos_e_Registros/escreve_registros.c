/*
    Author: Lucas Matheus Silva Pacheco
    RA:     112-686
    Date:   30/08/2020

    Description:
        * Writing data from people repeatedly until "empty" lastname is entered.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *NOME;

int input(char *str, int size);

int main()
{
    NOME primeiro_Nome, sobrenome;
    NOME endereco, cidade, estado, cep;
    NOME buffer;

    int   comprimento, comprimeto_Registro;
    FILE *NOME_ARQ;

    primeiro_Nome      = (char *)realloc(NULL, 30   * sizeof(char));
    sobrenome          = (char *)realloc(NULL, 30   * sizeof(char));
    endereco           = (char *)realloc(NULL, 30   * sizeof(char));
    cidade             = (char *)realloc(NULL, 30   * sizeof(char));
    estado             = (char *)realloc(NULL, 30   * sizeof(char));
    cep                = (char *)realloc(NULL, 30   * sizeof(char));
    buffer             = (char *)realloc(NULL, 180  * sizeof(char));

    if((NOME_ARQ = fopen("SAIDA2.txt", "wb")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir ou criar o arquivo para escrita.\n");
        exit(1);
    }

    fprintf(stdout, "Digite o sobrenome:\n");
    comprimento = input(sobrenome, 30);


    while (comprimento > 0)
    {
        buffer[0] = '\0';
        strcat(buffer, sobrenome);
        strcat(buffer, "|");

        fprintf(stdout, "Digite o primeiro nome:\n");
        input(primeiro_Nome, 30);

        fprintf(stdout, "Digite o endereco:\n");
        input(endereco, 30);   

        fprintf(stdout, "Digite a cidade:\n");
        input(cidade, 30);

        fprintf(stdout, "Digite o estado:\n");
        input(estado, 30);

        fprintf(stdout, "Digite o CEP:\n");
        input(cep, 30);
        
        strcat(buffer, primeiro_Nome);
        strcat(buffer, "|");
        strcat(buffer, endereco);
        strcat(buffer, "|");
        strcat(buffer, cidade);
        strcat(buffer, "|");
        strcat(buffer, estado);
        strcat(buffer, "|");
        strcat(buffer, cep);
        strcat(buffer, "|");

        comprimeto_Registro = strlen(buffer);

        fwrite(&comprimeto_Registro, sizeof(int), 1, NOME_ARQ);
        fwrite(buffer, comprimeto_Registro, 1, NOME_ARQ);

        fprintf(stdout, "Digite o sobrenome:\n");
        comprimento = input(sobrenome, 30);
    }

    free(sobrenome);
    free(primeiro_Nome);
    free(endereco);
    free(cidade);
    free(estado);
        

    fclose(NOME_ARQ);

    return 0;
}

int input(char *str, int size)
{
    int i = 0;
    char c = getchar();

    while (c != '\n')
    {
        if (size > 0)
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