/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Funções de ordenação.
    Date:        13/05/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Ordenacao.h"

Desempenho somaDesempenho(Desempenho d1, Desempenho d2)
{
    Desempenho total;

    total.nCompara = d1.nCompara + d2.nCompara;
    total.nOpera   = d1.nOpera   + d2.nOpera;
    total.tempo    = d1.tempo    + d2.tempo;

    return total;
}

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

Desempenho copiaVetor(int tam, vetor fonte, vetor destino)
{
    Desempenho TD;
    long int nComp = 0, nOper = 0;

    nComp++;
    nOper++;
    for (int i = 0; i < tam; i++)
    {
        destino[i] = fonte[i];

        nComp++;
        nOper += 3;
    }

    TD.nCompara = nComp;
    TD.nOpera   = nOper;

    return TD;
}

/* Metodos */
Desempenho selectionSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    long int nComp = 0, nOper = 0;
    
    int posOrd, i, menor, posMenor, aux;

    T1 = (long int)time(NULL);
    {
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
    long int nComp = 0, nOper = 0;

    int ultOrd, aux, ant;

    T1 = (long int)time(NULL);
    {
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
    long int nComp = 0, nOper = 0;

    int posOrd, prox, aux, ultTroca;

    T1 = (long int)time(NULL);
    {
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
    long int nComp = 0, nOper = 0;

    int ultOrd, aux, ant, desloc;

    T1 = (long int)time(NULL);
    {
        desloc = tam / 2;
        while (desloc > 0)
        {
            nComp++;
            nOper += 2;
            for (ultOrd = 0; ultOrd < tam - desloc; ultOrd++)
            {
                aux = V[ultOrd + desloc];
                ant = ultOrd;

                nComp += 2;
                while ((ant >= 0) && (V[ant] > aux))
                {
                    V[ant + desloc] = V[ant];
                    ant -= desloc;

                    nComp += 2;
                    nOper += 4;
                }

                V[ant + desloc] = aux;
                
                nComp++;
                nOper += 8;
            }

            desloc /= 2;
        }
    }
    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;
     
    return TD;
}

/*--------------------------------------------------------*/
/* Funções privadas para o MergeSort */
Desempenho merge(vetor V, int ini, int meio, int fim)
{
    Desempenho TD;
    long int nComp = 0, nOper = 0;

    vetor A1, A2;
    int tam1 = 0, tam2 = 0, i, j, k, maiorDeTodos;
    nOper += 2;

    nOper += 2;
    nComp++;
    for (i = ini; i < meio + 1; i++)
    {
        A1[tam1] = V[i];    
        tam1++;

        nOper += 6;
        nComp++;
    }

    nOper += 3;
    nComp++;
    for (i = meio + 1; i < fim + 1; i++)
    {
        A2[tam2] = V[i];
        tam2++;

        nOper += 6;
        nComp++;
    }

    maiorDeTodos = abs(A1[tam1 - 1]) + abs(A2[tam2 - 1]) + 1;

    A1[tam1] = maiorDeTodos;
    A2[tam2] = maiorDeTodos;

    i = j = 0;
    nOper += 11;

    nOper += 2;
    nComp++;
    for (k = ini; k < fim + 1; k++)
    {
        if (A1[i] < A2[j])
        {
            V[k] = A1[i];
            i++;

            nOper += 3;
        }
        else
        {
            V[k] = A2[j];
            j++;

            nOper += 3;
        }

        nOper += 2;
        nComp += 2;
    }

    TD.nCompara = nComp;
    TD.nCompara = nOper;

    return TD;
}

Desempenho _mergeSort(vetor V, int ini, int fim)
{   
    Desempenho TD, TD_Total;
    TD_Total.nCompara = 0;
    TD_Total.nOpera   = 0;
    TD_Total.tempo    = 0;

    long int nComp = 0, nOper = 0;

    int meio;

    nOper++;
    nComp++;
    if (fim - ini > 0)
    {
        meio = (ini + fim) / 2;
        TD = _mergeSort(V, ini, meio);
        TD_Total = somaDesempenho(TD_Total, TD);

        TD = _mergeSort(V, meio + 1, fim);
        TD_Total = somaDesempenho(TD_Total, TD);

        TD = merge(V, ini, meio, fim);
        TD_Total = somaDesempenho(TD_Total, TD);

        nOper += 4;
    }
    
    TD_Total.nCompara += nComp;
    TD_Total.nOpera += nOper;

    return TD_Total;
}
/*--------------------------------------------------------*/

Desempenho mergeSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    long int nComp = 0, nOper = 0;

    T1 = (long int)time(NULL);
    {
        nOper++;
        TD = _mergeSort(V, 0, tam - 1);
    }
    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nOpera += nOper;
     
    return TD;
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

Desempenho reorganizaMaxHeap(vetor V, int tam, int indice)
{
    Desempenho TD, TD_Total;
    TD_Total.nCompara = 0;
    TD_Total.nOpera   = 0;
    TD_Total.tempo    = 0;
    long int nComp = 0, nOper = 0;

    int maior, posMaior, aux, indiceFEsq, indiceFDir;

    maior = V[indice];
    posMaior = indice;
    
    nOper += 6;
    indiceFEsq = indiceFilhoEsquerda(indice);
    indiceFDir = indiceFilhoDireita(indice);

    nComp++;
    if (indiceFEsq  < tam)
    {
        nComp += 2;
        if (V[indiceFEsq] > maior)
        {
            maior = V[indiceFEsq];
            posMaior = indiceFEsq;
            nOper += 2;
        }

        if (indiceFDir < tam)
        {
            nComp++;
            if (V[indiceFDir] > maior)
            {
                maior = V[indiceFDir];
                posMaior = indiceFDir;
                nOper += 2;
            }
        }
    }

    nComp++;
    if (posMaior != indice)
    {
        aux = V[indice];
        V[indice] = maior;
        V[posMaior] = aux;
        nOper += 2;

        TD = reorganizaMaxHeap(V, tam, posMaior);
        TD_Total = somaDesempenho(TD, TD_Total);
    }

    TD_Total.nCompara += nComp;
    TD_Total.nOpera   += nOper;

    return TD_Total;
}

Desempenho criaMaxHeap(vetor V, int tam)
{    
    Desempenho TD_Total;
    TD_Total.nCompara = 0;
    TD_Total.nOpera   = 0;
    TD_Total.tempo    = 0;
    long int nComp = 0, nOper = 0;

    nComp++;
    nOper += 3;
    for (int i = (tam - 2) / 2; i > -1; i--)
    {
        TD_Total = reorganizaMaxHeap(V, tam, i);

        nComp++;
        nOper += 2;
    }

    TD_Total.nCompara += nComp;
    TD_Total.nOpera   += nOper;

    return TD_Total;
}
/*--------------------------------------------------------*/

Desempenho heapSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    long int nComp = 0, nOper = 0;

    int aux;

    T1 = (long int)time(NULL);
    {
        criaMaxHeap(V, tam);

        nComp++;
        nOper += 2;
        for (int i = tam - 1; i > 0; i--)
        {
            aux = V[i];
            V[i] = V[0];
            V[0] = aux;

            TD = reorganizaMaxHeap(V, i, 0);

            nComp++;
            nOper += 5;
        }
    }
    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara += nComp;
    TD.nOpera += nOper;

    return TD;
}

/*--------------------------------------------------------*/
/* Funções privadas para o QuickSort */
Desempenho particiona(vetor V, int ini, int fim, int *posDivisor)
{
    Desempenho TD;
    long int nComp = 0, nOper = 0;

    int divisor, i, aux, meio;

    nOper += 8;
    meio = (ini + fim) / 2;

    aux = V[fim];
    V[fim] = V[meio];
    V[meio] = aux;


    divisor = V[fim];
    *posDivisor = ini;

    nComp++;
    nOper++;
    for (i = ini; i < fim; i++)
    {
        if (V[i] < divisor)
        {
            aux = V[i];
            V[i] = V[*posDivisor];
            V[*posDivisor] = aux;
            (*posDivisor)++;

            nOper += 5;
        }

        nComp += 2;
        nOper += 2;
    }

    nOper += 2;
    V[fim] = V[*posDivisor];
    V[*posDivisor] = divisor;


    TD.nCompara = nComp;
    TD.nOpera = nOper;

    return TD;
}

Desempenho _quickSort(vetor V, int ini, int fim)
{
    Desempenho TD, TD_Total;
    TD_Total.nCompara = 0;
    TD_Total.nOpera   = 0;
    TD_Total.tempo    = 0;
    long int nComp = 0, nOper = 0;

    int posDivisor;

    nComp++;
    if (fim > ini)
    {
        TD = particiona(V, ini, fim, &posDivisor);
        TD_Total = somaDesempenho(TD, TD_Total);
        
        TD = _quickSort(V, ini, posDivisor - 1);
        TD_Total = somaDesempenho(TD, TD_Total);
        
        TD = _quickSort(V, posDivisor + 1, fim);
        TD_Total = somaDesempenho(TD, TD_Total);

        nOper += 2;
    }

    TD_Total.nCompara += nComp;
    TD_Total.nOpera   += nOper;

    return TD_Total;
}
/*--------------------------------------------------------*/
Desempenho quickSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    long int nComp = 0, nOper = 0;

    T1 = (long int)time(NULL);
    {
        nOper++;
        TD = _quickSort(V, 0, tam - 1);
    }
    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nOpera += nOper;
     
    return TD;
}

/*--------------------------------------------------------*/
/* Funções privadas para o CountingSort */
Desempenho registraContagem(vetor V, int tam, int intervalo, int *C)
{
    Desempenho TD;
    long int nComp = 0, nOper = 0;

    int i;

    nComp++;
    nOper++;
    for (i = 0; i < tam; i++)
    {
        C[V[i]]++;

        nComp++;
        nOper += 4;
    }

    nComp++;
    nOper++;
    for (i = 1; i < intervalo; i++)
    {
        C[i] += C[i - 1];
        
        nComp++;
        nOper += 5;
    }

    TD.nCompara = nComp;
    TD.nOpera   = nOper;

    return TD;
}

Desempenho transfereVetor(vetor V, int tam, int *C)
{
    Desempenho TD;
    long int nComp = 0, nOper = 0;
    
    vetor R;
    int i;

    nComp++;
    nOper++;
    for (i = tam - 1; i > -1; i--)
    {
        R[--C[V[i]]] = V[i];

        nComp++;
        nOper += 5;
    }

    TD = copiaVetor(tam, R, V); 

    TD.nCompara += nComp;
    TD.nOpera   += nOper;

    return TD;
}

/*--------------------------------------------------------*/
Desempenho countingSort(vetor V, int tam, int intervalo)
{
    long int T1, T2;
    Desempenho TD, TD_Total;
    TD_Total.nCompara = 0;
    TD_Total.nOpera   = 0;
    TD_Total.tempo    = 0;

    int *C;
    C = (int *)calloc(intervalo, sizeof(int));

    T1 = (long int)time(NULL);
    {
        TD = registraContagem(V, tam, intervalo, C);
        TD_Total = somaDesempenho(TD_Total, TD);
                        
        TD = transfereVetor(V, tam, C);
        TD_Total = somaDesempenho(TD_Total, TD);
    } 
    T2 = (long int)time(NULL);

    TD_Total.tempo = T2 - T1;

    return TD_Total;
}

/*--------------------------------------------------------*/
/* Funções privadas para o BucketSort */
int detectaBucket(vetorBuckets bucket, int nBuckets, int intervalo_Inicial, int intervalo_Final, int elem)
{
    int intervalo_Geral, tamanho_Intervalo_Bucket, nb;

    intervalo_Geral = intervalo_Final - intervalo_Inicial + 1;

    tamanho_Intervalo_Bucket = intervalo_Geral / nBuckets;

    nb = (elem - intervalo_Inicial) / tamanho_Intervalo_Bucket;

    return nb;
}
/*--------------------------------------------------------*/
Desempenho bucketSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    long int nComp = 0, nOper = 0;

    T1 = (long int)time(NULL);

    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;
     
    return TD;
}

Desempenho radixSort(vetor V, int tam)
{
    long int T1, T2;
    Desempenho TD;
    long int nComp = 0, nOper = 0;

    T1 = (long int)time(NULL);

    T2 = (long int)time(NULL);

    TD.tempo = T2 - T1;
    TD.nCompara = nComp;
    TD.nOpera = nOper;
     
    return TD;
}