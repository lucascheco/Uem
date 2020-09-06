#include <stdio.h>
#include <stdlib.h>

#define DELIM_STR "|"

int input(char *, int);

int main()
{
    char  sobrenome[30], nome[30], endereco[30], cidade[20], estado[3], cep[9];
    char  nome_arq[15];
    FILE *arq;
    int   tam;

    printf("Digite o nome do arquivo a ser criado: ");
    input(nome_arq, 15);

    if ((arq = fopen(nome_arq, "w")) == NULL) 
    {
        printf("Erro na criacao do arquivo --- programa abortado\n");
        exit(1);
    }

    printf("\nDigite o sobrenome ou <ENTER> para sair\n>>>");
    tam = input(sobrenome, 30);

    while (tam > 0)
    {
        printf("\nPrimeino nome\n>>>");
        input(nome,     30);

        printf("\nEndereco\n>>>");
        input(endereco, 30);

        printf("\nCidade\n>>>");
        input(cidade,   20);

        printf("\nEstado (sigla)\n>>>");
        input(estado,   3);

        printf("\nCEP\n>>>");
        input(cep,      9);


        fputs(sobrenome, arq);
        fputs(DELIM_STR, arq);

        fputs(nome, arq);
        fputs(DELIM_STR, arq);

        fputs(endereco, arq);
        fputs(DELIM_STR, arq);

        fputs(cidade, arq);
        fputs(DELIM_STR, arq);
        
        fputs(estado, arq);
        fputs(DELIM_STR, arq);

        fputs(cep, arq);
        fputs(DELIM_STR, arq);

        printf("\nDigite o sobrenome ou <ENTER> para sair\n>>>");
        tam = input(sobrenome, 30);
    }

    fclose(arq);
    
    return 0;
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