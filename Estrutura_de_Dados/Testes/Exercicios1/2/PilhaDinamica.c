#include <stdlib.h>
#include "PilhaDinamica.h"

void criaPilha(PILHA* pilha)
{
    *pilha = NULL;
}

int pilhaVazia(PILHA pilha)
{
    return pilha == NULL;
}

int pilhaCheia(PILHA pilha)
{
    return 0;
}

int topoPilha(PILHA pilha, DADO* topo)
{
    if (pilhaVazia(pilha))
        return 0;

    *topo = pilha->dado;

    return 1;
}

int empilha(PILHA* pilha, DADO dado)
{
    NO* aux;
    
    aux = (NO*)malloc(sizeof(NO));
    aux->dado = dado;
    aux->prox = *pilha;

    return 1;
}

int desempilha(PILHA* pilha, DADO* dado)
{
    if (pilhaVazia(*pilha))
        return 0;

    NO* aux;

    *dado = (*pilha)->dado;
    aux = *pilha;
    *pilha = aux->prox;

    free(aux);

    return 1;
}