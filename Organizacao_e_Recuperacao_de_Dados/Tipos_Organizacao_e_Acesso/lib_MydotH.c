#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_MydotH.h"

char  menu[3][30] = {
        "Digite o nome       : ",
        "Digite o CPF        : ",
        "Digite o Saldo atual: "
};

void allocaConta(Conta *conta)
{
    conta = (Conta *)malloc(sizeof(Conta));
    *conta = (Conta) malloc(sizeof(Registro));
    
    **(conta))->nome = (char *)malloc(NAMESIZE * sizeof(char));
    **conta->cpf  = (char *)malloc(CPFSIZE  * sizeof(char));
}

numChar getString(char *str, int size)
{
    numChar cont = 0;
    char c = getchar();    

    while (c != '\n')
    {
        if (size > 0)
        {
            str[cont] = c;
            c = getchar();  
        }
        cont++;
    }

    str[cont] = '\0';

    return cont;
}

Conta digitarCampos()
{
    Conta conta;
    
    allocaConta(conta);

    fprintf(stdout, "%s", menu[0]);
    getString(conta->nome, NAMESIZE);   
    
    if (conta->nome[0] == '\0')
    {
        return NULL;
    }


    fprintf(stdout, "%s", menu[1]);
    getString(conta->cpf, CPFSIZE);

    fprintf(stdout, "%s", menu[2]);
    scanf("%lf", &(conta->saldo));
    getchar();

    return conta;
}

void adicionarRegistroConta(Conta conta, FILE *arq)
{
    int tamanho_Registro = (int)(sizeof(conta->saldo) + strlen(conta->nome) + strlen(conta->cpf));
    fprintf(arq, "%d%s|%s|%lf|", tamanho_Registro, conta->nome, conta->cpf, conta->saldo);
}

void freeConta(Conta conta)
{
    free(conta->nome);
    free(conta->cpf);
    free(conta);
}