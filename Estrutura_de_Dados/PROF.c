#include <stdio.h>

#define tamVet 10

void leituraVetor(int A[])
{   int i;

    printf("\nLeitura do Vetor:\n");

    for (i=0; i<tamVet; i++)
    {
        printf("Digite A[%d] = ",i);
        scanf("%d",&A[i]);
    }

}

void escritaVetor(int A[])
{
    int i;

    printf("\nEscrita do Vetor:\n");

    for (i=0; i<tamVet; i++)
    {
        printf("\nA[%d] = %d",i, A[i]);
    }
}

void main(void)
{   int V[tamVet];
    float media;

    printf("\nPrograma Revis�o Vetor 1.0\n");

    leituraVetor(V);
    escritaVetor(V);
    media=mediaVetor(V);
    printf("\nMedia do Vetor = %.2f\n", media);
}