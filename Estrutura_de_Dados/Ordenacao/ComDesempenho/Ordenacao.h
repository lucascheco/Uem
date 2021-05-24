/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Protótipos de funções de ordenação.
    Date:        13/05/2021
************************************************************************************/


#define MAXVET 1000000

typedef int vetor[MAXVET];

typedef struct desempenho
{
    long int tempo;
    long int nCompara,nOpera;
} Desempenho;

void geraVetor(vetor V, int tam, int intervalo);

void mostraVetor(vetor V, int tam, char *mensagem);

Desempenho copiaVetor(int tam, vetor fonte, vetor destino);

#define MAXBUCKETS 10

typedef struct bucket
{
    vetor local;
    int pos;
    int tam;
} BUCKET;

typedef BUCKET vetorBuckets[MAXBUCKETS];

Desempenho selectionSort(vetor V, int tam);

Desempenho insertionSort(vetor V, int tam);

Desempenho bubbleSort   (vetor V, int tam);

Desempenho shellSort    (vetor V, int tam);

Desempenho mergeSort    (vetor V, int tam);

Desempenho heapSort     (vetor V, int tam);

Desempenho quickSort    (vetor V, int tam);

Desempenho countingSort (vetor V, int tam, int intervalo);

Desempenho bucketSort   (vetor V, int tam);

Desempenho radixSort    (vetor V, int tam);