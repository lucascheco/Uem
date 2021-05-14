#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Ordenacao.h"


void geraVetor(vetor V, int tam)
{
    srand(time(NULL));

    for (int i = 0; i < tam; i++)
        V[i] = rand() % 100;
    
}

void mostraVetor(vetor V, int tam)
{
    printf("\n\nELEMENTOS:\n");

    for (int i = 0; i < tam; i++)
        printf("%d ", V[i]);

    printf("\n\n");
}

void selectionSort(vetor V, int tam)
{
    int posOrd, i, menor, posMenor, aux;

    for (posOrd = 0; posOrd < tam - 1; posOrd++)
    {
        menor = V[posOrd];
        posMenor = posOrd;

        for (i = posOrd + 1; i < tam; i++)
            if (V[i] < menor)
                posMenor = i;

        aux = V[posOrd];
        V[posOrd] = menor;
        V[posMenor] = aux;
    }
}

void insertionSort(vetor V, int tam)
{

}

void bubbleSort   (vetor V, int tam)
{

}