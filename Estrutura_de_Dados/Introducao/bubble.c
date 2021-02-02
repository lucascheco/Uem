#include <stdio.h>


void bubble_sort(int v[], int tam)
{
    int i, trocou;
    do
    {
        trocou = 0;
        for (i = 0; i + 1 < tam; i++)
        {
            if (v[i] > v[i + 1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                trocou = 1;
            }
        }
    } while (trocou);
}

void show_vet(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
        printf("%d ", v[i]);

    printf("\n");
}

int main()
{   
    int v1[3] = {3, 5, 1}; /* 1 3 5*/
    int v2[] = {3, 8, 9, 11, 2, 5, 1, 4}; /* 1 2 3 4 5*/


    bubble_sort(v1, 3);
    bubble_sort(v2, 8);
    
    show_vet(v1, 3);
    show_vet(v2, 8);
    
    return 0;
}
