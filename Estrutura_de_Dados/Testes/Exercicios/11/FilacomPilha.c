#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilacomPilha.h"

void criaFila(FILA* fila)
{
    criaPilha(fila);
}

int filaCheia(FILA fila)
{
    return pilhaCheia(fila);
}

int filaVazia(FILA fila)
{
    return pilhaVazia(fila);
}

int primeiroFila(FILA fila, DADO* dado)
{
    if (pilhaVazia(fila))
        return 0;

    PILHA aux;
    int topo;
    criaPilha(&aux);

    while (!pilhaVazia(fila))
    {
        desempilha(&fila, dado);
        empilha(&fila, *dado);
    }

    topo  = topoPilha(aux);
    *dado = aux.pilha[topo];

    while (pilhaVazia(fila))
    {
        desempilha(&aux, dado);
        empilha(&aux, *dado);
    }

    return 1;
}

int enfileira(FILA* fila, DADO dado)
{
    if (pilhaCheia(*fila))
        return 0;

    empilha(fila, dado);
    
    return 1;
}

int desenfileira(FILA* fila, DADO* dado)
{
    if (pilhaVazia(*fila))
        return 0;

    DADO dado_dentro;
    PILHA aux;

    criaPilha(&aux);

    while (!pilhaVazia(*fila))
    {
        desempilha(fila, &dado_dentro);
        empilha(&aux, dado_dentro);
    }

    desempilha(&aux, &dado_dentro);

    *dado = dado_dentro;

    while (!pilhaVazia(aux))
    {
        desempilha(&aux, &dado_dentro);
        empilha(fila, dado_dentro);
    }

    return 1;
}