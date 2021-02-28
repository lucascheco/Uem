/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Lista encadeada ordenada, funções.
    Date:        23/02/2021
************************************************************************************/
#include <stdlib.h>
#include <string.h>
#include "ListaOrdEncad.h"


/*Privadas*/
int busca_Lista(LISTA L, char nome[], int* posAnterior)
{
    int posPosterior = L.ocupado;
        *posAnterior = TERRA;

    if(esta_vazia(L))
        return 0;
    else
    {
        int tem_Mais = L.lista[posPosterior].prox != TERRA;

        while (strcmp(L.lista[posPosterior].dado.nome, nome) == -1 && tem_Mais)
        {
            *posAnterior = posPosterior;
            posPosterior = L.lista[posPosterior].prox;
            tem_Mais = L.lista[posPosterior].prox != TERRA;
        }

        if (strcmp(L.lista[posPosterior].dado.nome, nome) == 0)
            return 1;
        else 
        if (strcmp(L.lista[posPosterior].dado.nome, nome) == 1)
            return 0;
        else
        {
            *posAnterior = posPosterior;
            return 0;
        }
    }
}

/*Publicas*/
void criaListaOrd(LISTA* L)
{
    for (int i = 0; i < MAXLIST - 1; ++i)
        L->lista[i].prox = i + 1;

    L->lista[MAXLIST - 1].prox = TERRA;
    
    L->quant   = 0;
    L->ocupado = TERRA;
    L->livre   = 0;
}

int esta_cheia(LISTA L)
{
    return L.quant == MAXLIST;
}

int esta_vazia(LISTA L)
{
    return L.quant == 0;
}

int quantidade(LISTA L)
{
    return L.quant;
}

int consulta_por_Nome(LISTA L, DADO* dado)
{
    if(esta_vazia(L))
        return 0;
    else
    {
        int posAnterior;

        if (busca_Lista(L, dado->nome, &posAnterior))
        {
            if (posAnterior == TERRA)
                *dado = L.lista[L.ocupado].dado;
            else
            {
                int prox = L.lista[posAnterior].prox;
                *dado = L.lista[prox].dado;
            }

            return 1;
        }

        return 0;        
    }
}

int consulta_por_Pos(LISTA L, int pos, DADO* dado)
{
    if (esta_vazia(L) || (pos > L.quant))
        return 0;
    else
    {
        int count = 1, posAux = L.ocupado;
        
        while (pos != count++)
            posAux = L.lista[posAux].prox;

        *dado = L.lista[posAux].dado;

        return 1; 
    }
}

int insere_Lista(LISTA* L, DADO dado)
{
    if (esta_cheia(*L))
        return 0;
    else
    {
        int posAnterior;

        if (busca_Lista(*L, dado.nome, &posAnterior))
            return 0;
        else
        {
            int aux = L->livre;
            L->livre = L->lista[aux].prox;
            L->lista[aux].dado = dado;

            if (posAnterior == TERRA)
            {
                L->lista[aux].prox = L->ocupado;
                L->ocupado = aux;
            }
            else
            {
                int prox = L->lista[posAnterior].prox;
                L->lista[aux].prox = prox;
                L->lista[posAnterior].prox = aux;
            }
            
            L->quant++;
            return 1;
        }
    }    

}

int remove_Lista(LISTA* L, DADO* dado)
{
    if(esta_vazia(*L))
        return 0;
    else
    {
        int posAnterior, prox;

        if (busca_Lista(*L, dado->nome, &posAnterior))
        {
            if (posAnterior == TERRA)
            {
                prox = L->ocupado;
                *dado = L->lista[L->ocupado].dado;
                L->ocupado = L->lista[prox].prox;
            }
            else
            {
                prox = L->lista[posAnterior].prox;
                *dado = L->lista[prox].dado;
                L->lista[posAnterior].prox = L->lista[prox].prox;
            }

            L->lista[prox].prox = L->livre;
            L->livre = prox;
            L->quant--;

            return 1;
        }

        return 0;
    }
}

int atualizar(LISTA* L, DADO dado_atual)
{
    DADO dado_antigo = dado_atual;
    if (!consulta_por_Nome(*L, &dado_antigo))
        return 0;
    
    remove_Lista(L, &dado_antigo);
    insere_Lista(L, dado_atual);
    return 1;   
}