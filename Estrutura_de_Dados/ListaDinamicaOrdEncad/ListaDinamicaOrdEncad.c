#include <stdlib.h>
#include "ListaDinamicaOrdEncad.h"

int busca_Lista(LISTA L, char nome[], ELEM* posAnterior)
{
    ELEM posPosterior = *(L.lista);
    posAnterior = NULL;

    if (esta_vazia(L))
        return 0;
    
    while (strcmp(posPosterior.dado.nome, nome) < 0 &&  posPosterior.prox != NULL)
    {
        posAnterior = &posPosterior;
        posPosterior = *(posPosterior.prox);
    }

    if (strcmp(posPosterior.dado.nome, nome) == 0)
        return 1;
    else 
    if (strcmp(posPosterior.dado.nome, nome) > 0)
        return 0;
    else 
    {
        *posAnterior = posPosterior;
        return 0;
    }
}

void criaListaOrd(LISTA* L)
{
    L->quant = 0;
    L->lista = NULL;
}

int esta_cheia(LISTA L)
{
    return 0;
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

}

int consulta_por_Pos(LISTA L, int pos, DADO* dado)
{

}

int insere_Lista(LISTA* L, DADO dado)
{
    ELEM* aux = (ELEM *)malloc(sizeof(ELEM));
    
    aux->dado = dado;
    aux->prox = L->lista;

    L->lista = aux;
    L->quant++;
}

int remove_Lista(LISTA* L, DADO* dado)
{
    if (esta_vazia(*L))
        return 0;
    else
    {
        ELEM posAnterior;

        if (!busca_Lista(*L, dado->nome, &posAnterior))
            return 0;

    }
}

int atualizar(LISTA* L, DADO dado_atual)
{

}