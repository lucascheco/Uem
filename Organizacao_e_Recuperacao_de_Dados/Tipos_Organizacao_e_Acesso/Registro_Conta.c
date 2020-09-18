#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_MydotH.h"

int main()
{
    FILE *arq;
    Conta conta;

    arq = fopen("contas.txt", "w");

    while ((conta = digitarCampos()) != NULL)
    {
        adicionarRegistroConta(conta, arq);
        freeConta(conta);
    }

    fclose(arq);
    return 0;
}

