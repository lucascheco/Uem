#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Filacircular.h"

void criaFila(FILA* fila)
{
    fila->total = 0;
    fila->prim = 0;
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

    *dado = fila.fila[fila.prim];

    return 1;
}

int enfileira(FILA* fila, DADO dado)
{
    if (filaCheia(*fila))
        return 0;
    
    if (fila->ultimo == MAXVET - 1)
        fila->ultimo = 0;
    else
        fila->ultimo++;

    fila->fila[fila->ultimo] = dado;
    fila->total++;
    
    return 1;
}

int desenfileira(FILA* fila, DADO* dado)
{
    if (filaVazia(*fila))
        return 0;
    
    *dado = fila->fila[fila->prim];

    if (fila->prim == MAXVET)
        fila->prim = 0;
    else
        fila->prim++;
    
}