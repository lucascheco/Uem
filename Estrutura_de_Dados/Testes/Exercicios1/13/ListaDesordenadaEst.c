/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Lista com arrasto, funções.
    Date:        21/02/2021
************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "ListaDesordenadaEst.h"

void criaLista(LISTA *lista)
{
    lista->quant = 0;

    for (int i = 0; i < MAXVET; ++i)
        lista->lista[i].status = 0;
}

int listaCheia(LISTA lista)
{
    return lista.quant == MAXVET;
}

int listaVazia(LISTA lista)
{
    return lista.quant == 0;
}

int quantidade(LISTA lista)
{
    return lista.quant;
}

int consultaNome(LISTA lista, DADO* dado)
{
    if (listaVazia(lista))
        return 0;

    int i = 0;
    int nelem = 0;
    int localizei = 0;

    while ((nelem < lista.quant) && (!localizei))
    {
        if (lista.lista[i].status == 1)
        {
            if (!strcmp(lista.lista[i].dado.nome, dado->nome))
            {
                *dado = lista.lista[i].dado;
                localizei = 1;
            }

            nelem++;
        }
        i++;
    }

    return localizei;
}

int consultaPosicao(LISTA lista, int pos, DADO* dado)
{
    if (pos >= lista.quant + 1 || pos <= 0)
        return 0;
    
    int i = 0;
    int nelem = 0;

    while (nelem != pos)
    {
        if (lista.lista[i].status == 1)
            nelem++;
        
        i++;
    }

    *dado = lista.lista[i - 1].dado;

    return 1;
}

int insereLista(LISTA* lista, DADO dado)
{
    if (listaVazia(*lista))
        return 0;
    
    if (consultaNome(*lista, &dado))
        return 0;
    
    int i = 0;
    int inserido = 0;
        
    do
    {
        if (lista->lista[i].status == 0)
        {
            lista->lista[i].dado = dado;
            lista->lista[i].status = 1;
            lista->quant++;

            inserido = 1;
        }

        i++;

    } while (!inserido);
    
    return 1;
}

int removeLista(LISTA* lista, DADO* dado)
{

}