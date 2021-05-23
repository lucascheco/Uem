/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Protótipos de funções de ordenação.
    Date:        13/05/2021
************************************************************************************/


#define MAXVET 1000000
#define MAXBUCKETS 10

typedef int vetor[MAXVET];

/* Funções auxiliares */
void geraVetor(vetor V, int tam, int intervalo);

void mostraVetor(vetor V, int tam, char *mensagem);


typedef struct bucket
{
    vetor local;
    int pos;
    int tam;
} BUCKET;

typedef BUCKET vetorBuckets[MAXBUCKETS];


/* Funções de Ordenação */
void selectionSort(vetor V, int tam);

void insertionSort(vetor V, int tam);

void bubbleSort   (vetor V, int tam);

void shellSort    (vetor V, int tam);

void mergeSort    (vetor V, int tam);

void heapSort     (vetor V, int tam);

void quickSort    (vetor V, int tam);

void countingSort (vetor V, int tam);

void bucketSort   (vetor V, int tam, int intervalo);

void radixSort    (vetor V, int tam);

void bubbleShellSort(vetor V, int tam);
