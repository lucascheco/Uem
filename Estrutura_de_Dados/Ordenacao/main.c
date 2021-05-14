
#include <stdio.h>
#include <stdlib.h>
#include "Ordenacao.h"

vetor V;

int main()
{
    int tam;

    printf("Programa de Ordenacao de Vetores\n");

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam); getchar();

    geraVetor(V, tam);
    mostraVetor(V, tam);
    selectionSort(V, tam);
    mostraVetor(V, tam);

    return 0;
}