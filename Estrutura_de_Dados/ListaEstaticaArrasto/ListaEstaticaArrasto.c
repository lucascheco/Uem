/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Lista com arrasto, funções.
    Date:        21/02/2021
************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "ListaEstaticaArrasto.h"

void cria_Lista(LISTA *L)
{
    L->quant = 0;

    for (int i = 0; i < MAXLIST; ++i)
        L->lista[i].status = 0;
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


int consulta_por_Nome(LISTA L, DADO *dado)
{
    if (esta_vazia(L))
        return 0;
    else
    {
        int i = 0;
        int nelem = 0;
        int localizei = 0;
        
        while ((nelem < L.quant) && (!localizei))
        {
            if (L.lista[i].status == 1)
            {
                if (!strcmp(L.lista[i].dado.nome, dado->nome))
                {
                    *dado = L.lista[i].dado;
                    localizei = 1;
                }
                nelem++;
            }
            i++;
        }
        return localizei;
    } 
}

int consulta_por_Pos(LISTA L, int pos, DADO* dado)
{
    if (pos >= L.quant+1 || pos <= 0)
        return 0;
    else
    {
        int i = 0;
        int nelem = 0; 
        
        while (nelem != pos)
        {
            if (L.lista[i].status == 1)
                nelem++;
            i++;
        }
        
        *dado = L.lista[i - 1].dado;

        return 1;
    }
}

int insere_Lista(LISTA* L, DADO dado)
{

    if (esta_cheia(*L))
        return 0;  
    else
    {
        if (consulta_por_Nome(*L, &dado))
            return 0;
        else
        {
            int i = 0;
            int inserido = 0;
            do
            {
                if (L->lista[i].status == 0)
                {
                    L->lista[i].dado = dado;
                    L->lista[i].status = 1;
                    L->quant++;

                    inserido = 1;
                }

                i++;

            } while (!inserido);
            
            return 1;
        }
    }
}

int remove_Lista(LISTA* L, DADO* dado)
{
    if (esta_vazia(*L))
        return 0;
    else
    {
        int i = 0;
        int nelem = 0;
        int localizei = 0;
        
        while ((nelem < L->quant) && (!localizei))
        {
            if (L->lista[i].status == 1)
            {
                if (!strcmp(L->lista[i].dado.nome, dado->nome))
                {
                    *dado = L->lista[i].dado;
                    L->lista[i].status = 0;
                    L->quant--;
                    localizei = 1;
                }
                nelem++;
            }
            i++;
        }
        return localizei;
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