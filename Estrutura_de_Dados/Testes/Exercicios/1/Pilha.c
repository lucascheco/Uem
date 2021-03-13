#include "Pilha.h"

void criaPilha(PILHA* pilha)
{
    pilha->topo = BASE;
}

int pilhaVazia(PILHA pilha)
{
    return pilha.topo == BASE;
}

int pilhaCheia(PILHA pilha)
{
    return pilha.topo == MAXVET - 1;
}

int topoPilha(PILHA pilha)
{
    return pilha.topo;
}

int empilha(PILHA* pilha, DADO dado)
{
    if (pilhaCheia(*pilha))
        return 0;
    
    pilha->topo++;
    pilha->pilha[pilha->topo] = dado;

    return 1;
}

int desempilha(PILHA* pilha, DADO* dado)
{
    if (pilhaVazia(*pilha))
        return 0;
        
    *dado = pilha->pilha[pilha->topo];
    pilha->topo--;

    return 1;
}