/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Aplicação principal de ordenação.
    Date:        13/05/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Ordenacao.h"

vetor V;

void clean_screen();
void mostraDesempenho(Desempenho RD);

int menu()
{   
    int op;
    
    printf("-----------------------------------------\n");
    printf(" Algoritmos de Ordenacao com desempenho\n");
    printf("-----------------------------------------\n");

    printf("Menu:\n");
    printf("1  - Selection Sort\n");
    printf("2  - Insertion Sort\n");
    printf("3  - Bubble Sort\n");
    printf("4  - Shell Sort\n");
    printf("5  - Merge Sort\n");
    printf("6  - Heap Sort\n");
    printf("7  - Quick Sort\n");
    printf("8  - Counting Sort\n");
    printf("9  - Bucket Sort\n");
    printf("10 - Radix Sort\n");
    printf("11 - Sair\n");
    printf("> ");
    
    scanf("%d", &op);
    getchar();

    return (op);
}

void option(int op)
{
    int tam, intervalo;
    Desempenho RD;

    if (op != 11)
    {
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tam); getchar();
        
        printf("Digite o intervalo de valores do vetor: ");
        scanf("%d", &intervalo); getchar();

        geraVetor(V, tam, intervalo);
        mostraVetor(V, tam, "Original\n");

        switch (op)
        {
        case 1:
            RD = selectionSort(V, tam);
            mostraVetor(V, tam, "Selection sort\n");
            mostraDesempenho(RD);
            printf("\n\n\n"); 
            break;
        case 2:
            RD = insertionSort(V, tam);
            mostraVetor(V, tam, "Insertion sort\n");
            mostraDesempenho(RD);
            printf("\n\n\n");      
            break;

        case 3:
            RD = bubbleSort(V, tam);
            mostraVetor(V, tam, "Bubble Sort\n");
            mostraDesempenho(RD);
            printf("\n\n\n");
            break;

        case 4:        
            RD = shellSort(V, tam);
            mostraVetor(V, tam, "Shell Sort\n");
            mostraDesempenho(RD);
            printf("\n\n\n");
            break;

            break;

        case 5:
            RD = mergeSort(V, tam);
            mostraVetor(V, tam, "Merge Sort\n");
            mostraDesempenho(RD);
            printf("\n\n\n");

            break;

        case 6:
            RD = heapSort(V, tam);
            mostraVetor(V, tam, "Heap Sort\n");
            mostraDesempenho(RD);
            printf("\n\n\n");

            break;

        case 7:
            RD = quickSort(V, tam);
            mostraVetor(V, tam, "Quick Sort\n");
            mostraDesempenho(RD);
            printf("\n\n\n");
            break;

        case 8:
            RD = countingSort(V, tam, intervalo);
            mostraVetor(V, tam, "Counting Sort\n");
            mostraDesempenho(RD);
            printf("\n\n\n");
            break;

        case 9:
            RD = bucketSort(V, tam);
            mostraVetor(V, tam, "Bucket Sort\n");
            mostraDesempenho(RD);
            printf("\n\n\n");
            break;
        
        case 10:
            RD = radixSort(V, tam);
            mostraVetor(V, tam, "Radix Sort\n");
            mostraDesempenho(RD);
            printf("\n\n\n");
            break;

        case 11:

            break;
    
        }  
    }
}

int main()
{
    int op;

    do
        option(op = menu());
    while (op != 11);

    return 0;
}

void clean_screen()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
}

void mostraDesempenho(Desempenho RD)
{
    printf("Medidas de desempenho: %ld segundos, ", RD.tempo);
    printf("%ld comparacoes, ", RD.nCompara);
    printf("%ld operacoes, ", RD.nOpera);
    printf("Total = %ld.\n", RD.nOpera + RD.nCompara);
}