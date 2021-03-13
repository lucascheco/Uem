#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhacomFila.h"

void criaPilha(PILHA* pilha)
{
    criaFila(pilha);
}

int pilhaVazia(PILHA pilha)
{
    return filaVazia(pilha);
}

int pilhaCheia(PILHA pilha)
{
    return filaCheia(pilha);
}

int topoPilha(PILHA pilha)
{
    return pilha.ultimo;
}

int empilha(PILHA* pilha, DADO dado)
{
    if (filaCheia(*pilha))
        return 0;

    enfileira(pilha, dado);

    return 1;
}

int desempilha(PILHA* pilha, DADO* dado)
{
    if (filaVazia(*pilha))
        return 0;
    
    DADO dado_dentro, dado_topo;
    FILA aux;

    criaFila(&aux);

    while (!filaVazia(*pilha))
    {
        desenfileira(pilha, &dado_dentro);
        enfileira(&aux, dado_dentro);
    }

    *dado = dado_topo = dado_dentro;

    while (!filaVazia(aux))
    {
        desenfileira(&aux, &dado_dentro);

        if (strcmp(dado_dentro.nome, dado_topo.nome) == 0)
            continue;
        
        enfileira(pilha, dado_dentro);
    }

    return 1;
}