#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"

void criaFila(FILA* fila)
{
    fila->total = 0;
    fila->ultimo = -1;
}

int filaVazia(FILA fila)
{
    return fila.total == 0;
}

int filaCheia(FILA fila)
{
    return fila.total == MAXVET;
}

int primeiroFila(FILA fila, DADO* dado)
{
    if (filaVazia(fila))
        return 0;

    *dado = fila.fila[0];

    return 1;
}

int enfileira(FILA* fila, DADO dado)
{
    if (filaCheia(*fila))
        return 0;
    
    fila->ultimo++;

    fila->fila[fila->ultimo] = dado;
    fila->total++;
    
    return 1;
}

int desenfileira(FILA* fila, DADO* dado)
{
    if (filaVazia(*fila))
        return 0;
    
    *dado = fila->fila[0];

    for (int i = 0; i + 1 < MAXVET; ++i)
    {
        fila->fila[i] = fila->fila[i + 1];
    }

    fila->ultimo--;
    fila->total--;

    return 1;
}