#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaDinamica.h"

void criaFila(FILA* fila)
{
    *fila = NULL;
}

int filaVazia(FILA fila)
{
    return fila == NULL;
}

int tem_um(FILA fila)
{
    return fila->prox == NULL;
}

int primeiroFila(FILA fila, DADO* dado)
{
    FILA primeiro;

    if (filaVazia(fila))
        return 0;

    primeiro = fila;

    while (primeiro->prox != NULL)
        primeiro = primeiro->prox;

    *dado = primeiro->dado;

    return 1;
}

int enfileira(FILA* fila, DADO dado)
{
    NO* aux;

    if ((aux = (NO*)malloc(sizeof(NO))) == NULL)
        return 0;

    aux->dado = dado;
    aux->prox = *fila;

    *fila = aux;

    return 1;
}

int desenfileira(FILA* fila, DADO* dado)
{

    if (filaVazia(*fila))
        return 0;

    FILA primeiro = *fila, segundo = NULL;

    while (primeiro->prox != NULL)
    {
        segundo = primeiro;
        primeiro = primeiro->prox;
    }

    *dado = primeiro->dado;

    if (segundo == NULL)
        *fila = NULL;
    else
        segundo->prox = NULL;
    
    free(primeiro);

    return 1;
}

/*8*/
int removeFila(FILA* fila, char nome[], DADO* dado)
{
    if (filaVazia(*fila))
        return 0;

    FILA fila_aux;
    DADO dado_aux;

    criaFila(&fila_aux);

    while (desenfileira(fila, &dado_aux))
    {
        printf("%s\n", dado_aux.nome);

        if (!strcmp(dado_aux.nome, nome))
        {
            *dado = dado_aux;
            continue;
        }

        enfileira(&fila_aux, dado_aux);
    }

    *fila = fila_aux;

    return 1;
}

/*9*/
int removeMenorfila(FILA* fila, DADO* dado)
{
    if (filaVazia(*fila))
        return 0;

    FILA   fila_aux;
    DADO   dado_aux;
    DADO   menorDado;

    criaFila(&fila_aux);
    primeiroFila(*fila, &menorDado);

    if (tem_um(*fila))
    {
        desenfileira(fila, &dado_aux);
        *fila = NULL;
        *dado = dado_aux;
        return 1;
    }

    while (desenfileira(fila, &dado_aux))
    {
        if (strcmp(dado_aux.nome, menorDado.nome) < 0)
            menorDado = dado_aux;
        
        enfileira(&fila_aux, dado_aux);
    }

    while (desenfileira(&fila_aux, &dado_aux))
    {
        if (strcmp(dado_aux.nome, menorDado.nome) == 0)
            continue;
        
        enfileira(fila, dado_aux);
    }

    *dado = menorDado;
    
    return 1;
}

/*10*/
void ordenafila(FILA* fila)
{
    FILA  fila_ordenada;
    DADO   dado_aux;

    criaFila(&fila_ordenada);

    while (removeMenorfila(fila, &dado_aux))
        enfileira(&fila_ordenada, dado_aux);

    *fila = fila_ordenada;

}