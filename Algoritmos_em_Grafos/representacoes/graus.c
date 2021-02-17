#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef size_t st;

int* graus_de_saida(int* adj[], st n)
{
    int* graus = calloc(n, sizeof(int));

    if (graus == NULL)
        return NULL;

    for (st u = 0; u < n; ++u)
        for (int* v = adj[u]; *v != -1; v++)
            graus[u]++;

}

int* graus_de_entrada(int* adj[], st n)
{
    int* graus = calloc(n, sizeof(int));
 
    if (graus == NULL)
        return NULL;
    
    for (st u = 0; u < n; ++u)
        for (st i = 0; adj[u][i] != -1; ++i)
        {
            int v = adj[u][i];
            graus[v]++;
        }
}

int main()
{
    int* adj[6] = {
        (int[]) { 1, 3, -1 },
        (int[]) { 4, -1 },
        (int[]) { 5, 4, -1 },
        (int[]) { 1, -1 },
        (int[]) { 3, -1 },
        (int[]) { 5, -1 },
    };

    int N = 6;

    int* gsaida = graus_de_saida(adj, N);

    assert(gsaida != NULL);
    assert(gsaida[0] == 2);
    assert(gsaida[1] == 1);
    assert(gsaida[2] == 2);
    assert(gsaida[3] == 1);
    assert(gsaida[4] == 1);
    assert(gsaida[5] == 1);

    free(gsaida);

    printf("Funcao graus de saida: Tudo certo.\n");

    int* gentrada = graus_de_entrada(adj, N);

    assert(gentrada != NULL);
    assert(gentrada[0] == 0);
    assert(gentrada[1] == 2);
    assert(gentrada[2] == 0);
    assert(gentrada[3] == 2);
    assert(gentrada[4] == 2);
    assert(gentrada[5] == 2);
    
    free(gentrada);

    printF("Funcao graus de entrada: Tudo certo.\n");

    return 0;
}