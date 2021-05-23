/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Funções de ordenação.
    Date:        13/05/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Ordenacao.h"

void geraVetor(vetor V, int tam, int intervalo)
{
    srand(time(NULL));

    for (int i = 0; i < tam; i++)
        V[i] = rand() % intervalo;

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

void copiaVetor(int tam, vetor fonte, vetor destino)
{
    for (int i = 0; i < tam; i++)
        destino[i] = fonte[i];
}

/*****************/
/**** Metodos ****/
/*****************/
void selectionSort(vetor V, int tam)
{
    int posOrd, i, menor, posMenor, aux;

    for (posOrd = 0; posOrd < tam - 1; posOrd++)
    {
        menor = V[posOrd];
        posMenor = posOrd;
        
        for (i = posOrd + 1; i < tam; i++)
            if (V[i] < menor)
            {
                posMenor = i;
                menor = V[i];
            }

        aux = V[posOrd];
        V[posOrd] = menor;
        V[posMenor] = aux;
    }
}

/*  
    Insertion Sort Descrescente
    Sem repetição de elementos.
*/
// void insertionSort(vetor V, int *tam)
// {
//     int ultOrd, aux, ant;
    
//     for (ultOrd = 0; ultOrd < *(tam) - 1; ultOrd++)
//     {
//         aux = V[ultOrd + 1];
//         ant = ultOrd;

//         while ((ant >= 0) && (V[ant] < aux))
//         {
//             V[ant + 1] = V[ant];
//             ant--;
//         }

//         V[ant + 1] = aux;
//     }

//     for (int i = 0; i < *tam; i++)
//     {
//         for (int j = i + 1; j < *tam;)
//         {
//             if(V[j] == V[i])
//             {
//                 for(int k = j; k < *tam; k++)
//                     V[k] = V[k + 1];

//                 (*tam)--;
//             }
//             else
//                 j++;           
//         }
//     }
// }

void insertionSort(vetor V, int tam)
{
    int ultOrd, aux, ant;
    
    for (ultOrd = 0; ultOrd < tam - 1; ultOrd++)
    {
        aux = V[ultOrd + 1];
        ant = ultOrd;

        while ((ant >= 0) && (V[ant] > aux))
        {
            V[ant + 1] = V[ant];
            ant--;
        }

        V[ant + 1] = aux;
    }
}

void bubbleSort(vetor V, int tam)
{
    int posOrd, prox, aux, ultTroca;

    posOrd = tam - 1;
    
    while (posOrd > 0)
    {
        ultTroca = 0;

        for (prox = 0; prox < posOrd; prox++)
            if (V[prox] > V[prox + 1])
            {
                aux = V[prox];
                V[prox] = V[prox + 1];
                V[prox + 1] = aux;
                ultTroca = prox;
            }
        
        posOrd = ultTroca;
    }
}

void shellSort(vetor V, int tam)
{
    int ultOrd, aux, ant, desloc;

    desloc = tam / 2;

    while (desloc > 0)
    {
        for (ultOrd = 0; ultOrd < tam - desloc; ultOrd++)
        {
            aux = V[ultOrd + desloc];
            ant = ultOrd;

            while ((ant >= 0) && (V[ant] > aux))
            {
                V[ant + desloc] = V[ant];
                ant -= desloc;
            }

            V[ant + desloc] = aux;
        }

        desloc /= 2;
    }
}

// void bubbleShellSort(vetor V, int tam)
// {
//     int posOrd, prox, aux, ultTroca;
    
//     int ultOrd, ant, desloc;

//     desloc = tam / 2;

//     while (desloc > 0)
//     {
//         posOrd = tam - desloc;
        
//         while (posOrd > 0)
//         {
//             ultTroca = 0;

//             for (prox = 0; prox < posOrd; prox++)
//                 if (V[prox] > V[prox + desloc])
//                 {
//                     aux = V[prox];
//                     V[prox] = V[prox + desloc];
//                     V[prox + desloc] = aux;
//                     ultTroca = prox;
//                 }
            
//             posOrd = ultTroca;
//         }
        
//         desloc /= 2;
//     }
// }

/*--------------------------------------------------------*/
/* Funções privadas para o MergeSort */
void merge(vetor V, int ini, int meio, int fim)
{
    vetor A1, A2;
    int tam1 = 0, tam2 = 0, i, j, k, maiorDeTodos;

    for (i = ini; i < meio + 1; i++)
        A1[tam1++] = V[i];    

    for (i = meio + 1; i < fim + 1; i++)
        A2[tam2++] = V[i];
    
    maiorDeTodos = abs(A1[tam1 - 1]) + abs(A2[tam2 - 1]) + 1;

    A1[tam1] = maiorDeTodos;
    A2[tam2] = maiorDeTodos;

    i = j = 0;

    for (k = ini; k < fim + 1; k++)
        if (A1[i] < A2[j])
            V[k] = A1[i++];
        else
            V[k] = A2[j++];
            
}

void _mergeSort(vetor V, int ini, int fim)
{   
    int meio;

    if (fim - ini > 0)
    {
        meio = (ini + fim) / 2;

        _mergeSort(V, ini, meio);

        _mergeSort(V, meio + 1, fim);

        merge(V, ini, meio, fim);
    }
}
/*--------------------------------------------------------*/

void mergeSort(vetor V, int tam)
{
    _mergeSort(V, 0, tam - 1);
}

/*--------------------------------------------------------*/
/* Funções privadas para o HeapSort */
int indiceFilhoEsquerda(int indice)
{
    return 2 * indice + 1;
}

int indiceFilhoDireita(int indice)
{
    return 2 * indice + 2;
}

void reorganizaMaxHeap(vetor V, int tam, int indice)
{
    int maior, posMaior, aux, indiceFEsq, indiceFDir;

    maior = V[indice];
    posMaior = indice;

    indiceFEsq = indiceFilhoEsquerda(indice);
    indiceFDir = indiceFilhoDireita(indice);

    if (indiceFEsq  < tam)
    {
        if (V[indiceFEsq] > maior)
        {
            maior = V[indiceFEsq];
            posMaior = indiceFEsq;
        }

        if (indiceFDir < tam)
            if (V[indiceFDir] > maior)
            {
                maior = V[indiceFDir];
                posMaior = indiceFDir;
            }
        
    }

    if (posMaior != indice)
    {
        aux = V[indice];
        V[indice] = maior;
        V[posMaior] = aux;
    
        reorganizaMaxHeap(V, tam, posMaior);
    }
}

void criaMaxHeap(vetor V, int tam)
{
    for (int i = (tam - 2) / 2; i > -1; i--)
        reorganizaMaxHeap(V, tam, i);
    
}

/*--------------------------------------------------------*/

void heapSort(vetor V, int tam)
{
    int aux;

    criaMaxHeap(V, tam);

    for (int i = tam - 1; i > 0; i--)
    {
        aux = V[i];
        V[i] = V[0];
        V[0] = aux;

        reorganizaMaxHeap(V, i, 0);
    }
}

/*--------------------------------------------------------*/
/* Funções privadas para o QuickSort */
void particiona(vetor V, int ini, int fim, int *posDivisor)
{
    int divisor, i, aux, meio;

    meio = (ini + fim) / 2;

    aux = V[fim];
    V[fim] = V[meio];
    V[meio] = aux;

    divisor = V[fim];
    *posDivisor = ini;

    for (i = ini; i < fim; i++)
        if (V[i] < divisor)
        {
            aux = V[i];
            V[i] = V[*posDivisor];
            V[*posDivisor] = aux;
            (*posDivisor)++;
        }

    V[fim] = V[*posDivisor];
    V[*posDivisor] = divisor;
}

void _quickSort(vetor V, int ini, int fim)
{
    int posDivisor;

    if (fim > ini)
    {
        particiona(V, ini, fim, &posDivisor);
        
        _quickSort(V, ini, posDivisor - 1);
        
        _quickSort(V, posDivisor + 1, fim);
    }
}
/*--------------------------------------------------------*/
void quickSort(vetor V, int tam)
{
    _quickSort(V, 0, tam - 1);
}

/*--------------------------------------------------------*/
/* Funções privadas para o CountingSort */
void registraContagem(vetor V, int tam, int intervalo, int *C)
{
    int i;

    for (i = 0; i < tam; i++)
        C[V[i]]++;
    
    for (i = 1; i < intervalo; i++)
        C[i] += C[i - 1];
    
}

void transfereVetor(vetor V, int tam, int *C)
{
    vetor R;
    int i;
    
    for (i = tam - 1; i > -1; i--)
        R[--C[V[i]]] = V[i];

    copiaVetor(tam, R, V); 
}

/*--------------------------------------------------------*/
void countingSort(vetor V, int tam, int intervalo)
{
    int *C;
    C = (int *)calloc(intervalo, sizeof(int));

    registraContagem(V, tam, intervalo, C);
                    
    transfereVetor(V, tam, C);

    free(C);
}

/*--------------------------------------------------------*/
/* Funções privadas para o BucketSort */
int detectaBucket(vetorBuckets bucket, int nBuckets, int intervIni, int intervFim, int elem)
{
    int interv_Geral, tam_Interv_Bucket, nb;

    interv_Geral = intervFim - intervIni + 1;

    tam_Interv_Bucket = interv_Geral / nBuckets;

    nb = (elem - intervIni) / tam_Interv_Bucket;

    return nb;
}

void distribuiBucket(vetor V, int tam, vetorBuckets bucket, int nBuckets, int intervIni, int intervFim)
{
    int i, nb;

    for (i = 0; i < nBuckets; ++i)
        bucket[i].tam = 0; 
    
    for (i = 0; i < tam; ++i) 
    {
        nb = detectaBucket(bucket, nBuckets, intervIni, intervFim, V[i]);
        bucket[nb].local[bucket[nb].tam] = V[i];
        bucket[nb].tam++;
    }
}

void ordenaBucket(vetor V, int tam, vetorBuckets bucket, int nBuckets, int intervalo)
{
    int i, j, nb, pos = 0;

    for (i = 0; i < nb; ++i)
    {
       mergeSort(bucket[i].local, bucket[i].tam);

      for (j = 0; j < bucket[i].tam; ++j)
          V[pos++] = bucket[i].local[j];
    
    }
}

void _bucketSort(vetor V, int tam, int intervalo)
{
    int i, j, nBuckets, pos;
    
    vetorBuckets VB;
    
    distribuiBucket(V, tam, VB, 10, 0, intervalo);

    ordenaBucket(V, tam, VB, 10, intervalo);

}

/*--------------------------------------------------------*/
void bucketSort(vetor V, int tam, int intervalo)
{
    _bucketSort(V, tam, intervalo);
}

void radixSort(vetor V, int tam)
{

}


// void registraContagem(vetor V, int tam, int intervalo, vetor C)
// {
//     int i;

//     for (i = 0; i < tam; i++)
//     {
//         C[V[i]]++;
//     }
    
//     for (i = 1; i < intervalo; i++)
//     {
//         C[i] = C[i] + C[i - 1];
//     }
// }

// void transfereVetor(vetor V, int tam, vetor C)
// {
//     vetor R;
//     int i, k;
    
//     for (i = tam - 1; i > -1; i--)
//     {
//         C[V[i]]--;
//         k = C[V[i]];
//         R[k] = V[i];
//     }

//     copiaVetor(tam, R, V); 
// }

// /*--------------------------------------------------------*/
// void countingSort(vetor V, int tam)
// {
//     vetor C;
//     int maior, menor, intervalo;

//     maior = menor = V[0];
    
//     for (int i = 1; i < tam; i++)
//     {
//         if (V[i] > maior)
//             maior = V[i];

//         if (V[i] < menor)
//             menor = V[i];
//     }

//     intervalo = maior + 1;

//     for (int i = 0; i <= intervalo; i++)
//         C[i] = 0;

//     registraContagem(V, tam, intervalo, C);
                    
//     transfereVetor(V, tam, C);
// }
