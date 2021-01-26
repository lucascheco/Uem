/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Simple Vectors
    Date:        21/01/2021
************************************************************************************/

#include <stdio.h>

#define VET_BUFFER 30

int read_Vec(int vet[]);
int write_Vec(int vet[], int num);
double vet_Average(int vet[], int num);

int main()
{
    int vet[VET_BUFFER];
    int num_Elements;   /* Number of elements */
    double average;

    
    printf("\nType your values or character to exit: \n");
    if (!(num_Elements = read_Vec(vet)))
    {
        fprintf(stderr, "Error: the number of elements cant be 0 and must be in buffer vector range.\n");
        return 1;
    }

    printf("Your vector: \n");
    write_Vec(vet, num_Elements);

    printf("Average of %d elements: %.3lf\n", num_Elements, vet_Average(vet, num_Elements));

    return 0;
}

int read_Vec(int vet[])
{
    int i = 0;

    while(scanf("%d", vet + i))
        i++;
    
    if (i > VET_BUFFER)
        i = 0;

    return i;
}

int write_Vec(int vet[], int num)
{   
    printf("\nVET = { ");
    for (int i = 0; i < num; i++)
        printf("%d ", vet[i]);
    printf("}\n");
}

double vet_Average(int vet[], int num)
{
    double sum = 0.0;
    for (int i = 0; i < num; i++)
        sum += (double)vet[i];
    
    return sum / (double)num;
}