#include "Pilha.h"
#include <string.h>

void criaPilha(PILHA* pilha)
{
    pilha->topo = BASE;
}

int pilhaVazia(PILHA pilha)
{
    return pilha.topo == BASE;
}

int tem_um(PILHA pilha)
{
    return pilha.topo == 0;
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

int removeMenorPilha(PILHA* pilha, DADO* dado)
{
    if (pilhaVazia(*pilha))
        return 0;

    PILHA  pilha_aux;
    DADO   dado_aux;
    DADO   menorDado;

    criaPilha(&pilha_aux);

    int topo = topoPilha(*pilha);

    menorDado = pilha->pilha[topo];

    if (tem_um(*pilha))
    {
        desempilha(pilha, &dado_aux);
        *dado = dado_aux;
        return 1;
    }

    while (!pilhaVazia(*pilha))
    {
        desempilha(pilha, &dado_aux);

        if (strcmp(dado_aux.nome, menorDado.nome) < 0)
            menorDado = dado_aux;
        
        empilha(&pilha_aux, dado_aux);
    }

    while (!pilhaVazia(pilha_aux))
    {
        desempilha(&pilha_aux, &dado_aux);

        if (strcmp(dado_aux.nome, menorDado.nome) == 0)
            continue;
        
        empilha(pilha, dado_aux);
    }

    *dado = menorDado;
    
    return 1;
}