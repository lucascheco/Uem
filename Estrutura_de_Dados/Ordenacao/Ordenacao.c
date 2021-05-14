/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Funções de ordenação.
    Date:        13/05/2021
************************************************************************************/

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

void mostraVetor(vetor V, int tam, char *mensagem)
{
    printf("\nELEMENTOS: %s\n", mensagem);

    if (tam < 2000)
        for (int i = 0; i < tam; i++)
            printf("%d ", V[i]);
    else
        printf("Impressao omitida.\n");

    printf("\n");
}


/* Metodos */
Desempenho selectionSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    double nComp = 0, nOper = 0;
    
    int posOrd, i, menor, posMenor, aux;

    T1 = (long int)time(NULL);
    nComp++;
    nOper += 2;
    for (posOrd = 0; posOrd < tam - 1; posOrd++)
    {
        menor = V[posOrd];
        posMenor = posOrd;
        
        for (i = posOrd + 1; i < tam; i++)
        {
            if (V[i] < menor)
            {
                posMenor = i;
                menor = V[i];

                nOper += 2;
            }

            nOper++;
            nComp += 2;
        }

        aux = V[posOrd];
        V[posOrd] = menor;
        V[posMenor] = aux;

        nOper += 9;
        nComp += 2;
    }

    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;

    return TD;
}

Desempenho insertionSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    double nComp = 0, nOper = 0;

    int ultOrd, aux, ant;

    T1 = (long int)time(NULL);
    nComp++;
    nOper += 2;
    for (ultOrd = 0; ultOrd < tam - 1; ultOrd++)
    {
        aux = V[ultOrd + 1];
        ant = ultOrd;

        nComp += 2;
        while ((ant >= 0) && (V[ant] > aux))
        {
            V[ant + 1] = V[ant];
            ant--;

            nComp += 2;
            nOper += 4;
        }

        V[ant + 1] = aux;
        
        nComp++;
        nOper += 8;
    }

    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;
     
    return TD;
}

Desempenho bubbleSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    double nComp = 0, nOper = 0;

    int posOrd, prox, aux, ultTroca;

    T1 = (long int)time(NULL);
    
    nOper += 2;
    posOrd = tam - 1;
    
    nComp++;
    while (posOrd > 0)
    {
        ultTroca = 0;

        for (prox = 0; prox < posOrd; prox++)
        {
            if (V[prox] > V[prox + 1])
            {
                aux = V[prox];
                V[prox] = V[prox + 1];
                V[prox + 1] = aux;
                ultTroca = prox;

                nOper += 6;
            }

            nComp += 2;
            nOper += 2;
        }

        posOrd = ultTroca;

        nComp += 2;
        nOper += 3;
    }
    
    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;
     
    return TD;
}

Desempenho shellSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    double nComp = 0, nOper = 0;

    T1 = (long int)time(NULL);

    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;
     
    return TD;
}

Desempenho mergeSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    double nComp = 0, nOper = 0;

    T1 = (long int)time(NULL);

    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;
     
    return TD;
}

Desempenho heapSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    double nComp = 0, nOper = 0;

    T1 = (long int)time(NULL);

    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;
     
    return TD;
}

Desempenho quickSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    double nComp = 0, nOper = 0;

    T1 = (long int)time(NULL);

    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;
     
    return TD;
}
Desempenho countingSort(vetor V, int tam)
{

}

Desempenho bucketSort(vetor V, int tam)
{
    
}

Desempenho radixSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    double nComp = 0, nOper = 0;

    T1 = (long int)time(NULL);

    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;
     
    return TD;
}