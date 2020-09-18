#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_MydotH.h"

int main()
{
    Conta conta;
    FILE *arq;
    char *nomeArq;
    int   tamanho_Registro, tamanho_Nome;
 

    nomeArq = (char *)malloc(NAMESIZE * sizeof(char));

    fprintf(stdout, "Digite o nome do arquivo a ser lido: ");
    fscanf (stdin,  "%[^\n]s", nomeArq);

    if ((arq = fopen(nomeArq, "r")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir para leitura.\n");
        exit(1);
    }
    /* 
        Como nesse caso o tamanho de dois campos
        são fixos, podemos calcular o tamanho do 
        nome que é variável.
    */

    while (fscanf(arq, "%d", &tamanho_Registro) && !feof(arq))
    {
        allocaConta(conta);

        tamanho_Nome = tamanho_Registro - CPFSIZE - 8;
        
        fread(conta->nome, tamanho_Nome, 1, arq);
        fseek(arq, 1, SEEK_CUR);

        fread(conta->cpf, CPFSIZE, 1, arq);
        fseek(arq, 1, SEEK_CUR);

        fscanf(arq, "%lf", &(conta->saldo)); 
        fseek(arq, 1, SEEK_CUR);     

                    
        fprintf(stdout, "%s\n", conta->nome);
        fprintf(stdout, "%s\n", conta->cpf);
        fprintf(stdout, "%lf\n", conta->saldo);  

        freeConta(conta);
    }

    

    return 0;
}