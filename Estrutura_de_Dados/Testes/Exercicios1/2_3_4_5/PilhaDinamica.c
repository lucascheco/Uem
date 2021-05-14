#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PilhaDinamica.h"

void criaPilha(PILHA* pilha)
{
    *pilha = NULL;
}

int pilhaVazia(PILHA pilha)
{
    return pilha == NULL;
}

int tem_um(PILHA pilha)
{
    return pilha->prox == NULL;
}

int pilhaCheia()
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

    *pilha = aux;

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

/*3*/
int removePilha(PILHA* pilha, char nome[], DADO* dado)
{
    if (pilhaVazia(*pilha))
        return 0;

    PILHA pilha_aux;
    DADO dado_aux;

    criaPilha(&pilha_aux);

    while (!pilhaVazia(*pilha))
    {
        desempilha(pilha, &dado_aux);
        if (!strcmp(dado_aux.nome, nome))
        {
            *dado = dado_aux;
            continue;
        }
        empilha(&pilha_aux, dado_aux);
    }

    while (!pilhaVazia(pilha_aux))
    {
        desempilha(&pilha_aux, &dado_aux);
        empilha(pilha, dado_aux);
    }
    
    return 1;
}

/*4*/
int removeMenorPilha(PILHA* pilha, DADO* dado)
{
    if (pilhaVazia(*pilha))
        return 0;

    PILHA  pilha_aux;
    DADO   dado_aux;
    DADO   menorDado;

    criaPilha(&pilha_aux);
    topoPilha(*pilha, &menorDado);

    if (tem_um(*pilha))
    {
        desempilha(pilha, &dado_aux);
        *pilha = NULL;
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

/*5*/
void ordenaPilha(PILHA* pilha)
{
    PILHA  pilha_ordenada;
    DADO   dado_aux;

    criaPilha(&pilha_ordenada);

    while (removeMenorPilha(pilha, &dado_aux))
        empilha(&pilha_ordenada, dado_aux);

    *pilha = pilha_ordenada;

}