/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Protótipos de funções de ordenação.
    Date:        13/05/2021
************************************************************************************/


#define MAXVET 10000000

typedef int vetor[MAXVET];

typedef struct desempenho
{
    long int tempo;
    double nCompara,nOpera;
} Desempenho;

void geraVetor(vetor V, int tam);

void mostraVetor(vetor V, int tam, char *mensagem);


Desempenho selectionSort(vetor V, int tam);

Desempenho insertionSort(vetor V, int tam);

Desempenho bubbleSort   (vetor V, int tam);

Desempenho shellSort    (vetor V, int tam);

Desempenho mergeSort    (vetor V, int tam);

Desempenho heapSort     (vetor V, int tam);

Desempenho quickSort    (vetor V, int tam);

Desempenho countingSort (vetor V, int tam);

Desempenho bucketSort   (vetor V, int tam);

Desempenho radixSort    (vetor V, int tam);