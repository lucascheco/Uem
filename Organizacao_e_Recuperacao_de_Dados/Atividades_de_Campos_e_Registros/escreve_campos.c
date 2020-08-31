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
typedef unsigned int CEP;

int input(char *str, int size);

int main()
{
    NOME primeiro_Nome, sobrenome, sobrenome_anterior; /* Usei uma outra variável para poder usar o sscanf, mas estou ciente da outra forma informada na atividade */
    NOME endereco, cidade, estado;
    CEP  cep;

    int   comprimento;
    char  caractere_enter = '\t';
    int   num_de_char = 0;
    FILE *NOME_ARQ;

    primeiro_Nome      = (char *)realloc(NULL, 30 * sizeof(char));
    sobrenome          = (char *)realloc(NULL, 30 * sizeof(char));
    endereco           = (char *)realloc(NULL, 30 * sizeof(char));
    cidade             = (char *)realloc(NULL, 30 * sizeof(char));
    estado             = (char *)realloc(NULL, 30 * sizeof(char));
    sobrenome_anterior = (char *)realloc(NULL, 30 * sizeof(char));

    if((NOME_ARQ = fopen("SAIDA.txt", "w")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir ou criar o arquivo para escrita.\n");
        exit(1);
    }

    fprintf(stdout, "Digite o sobrenome:\n");
    comprimento = input(sobrenome, 30);


    while (comprimento > 0)
    {
        fprintf(stdout, "Digite o primeiro nome:\n");
        input(primeiro_Nome, 30);

        fprintf(stdout, "Digite o endereco:\n");
        input(endereco, 30);   

        fprintf(stdout, "Digite a cidade:\n");
        input(cidade, 30);

        fprintf(stdout, "Digite o estado:\n");
        input(estado, 30);

        fprintf(stdout, "Digite o CEP:\n");
        fscanf(stdin, "%d", &cep);
        getchar();
        
        fprintf(NOME_ARQ, "%s|", sobrenome);
        fprintf(NOME_ARQ, "%s|", primeiro_Nome);
        fprintf(NOME_ARQ, "%s|", endereco);
        fprintf(NOME_ARQ, "%s|", cidade);
        fprintf(NOME_ARQ, "%s|", estado);
        fprintf(NOME_ARQ, "%d|", cep);

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