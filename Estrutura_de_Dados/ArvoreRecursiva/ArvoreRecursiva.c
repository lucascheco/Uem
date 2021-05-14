/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Árvores Binárias Recursivas, funções.
    Date:        15/04/2021
************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreRecursiva.h"

void printNo(ARVORE No)
{
    printf("\nNome: %s RG: %d Idade: %d\n", No->dado.nome, No->dado.RG, No->dado.idade);
}

DADO maiorDosMenores(ARVORE *esquerda)
{
    ARVORE aux_A;
    DADO   aux_D;

    aux_A = *esquerda;

    if (ABB_estaVazia((*esquerda)->dir))
    {
        aux_D = aux_A->dado;
        (*esquerda) = aux_A->esq;
        free(aux_A);
    }
    else
        aux_D = maiorDosMenores(&(aux_A->dir));

    return aux_D;
}

DADO menorDosMaiores(ARVORE *direita)
{
    ARVORE aux_A;
    DADO   aux_D;

    aux_A = *direita;

    if (ABB_estaVazia((*direita)->esq))
    {
        aux_D = aux_A->dado;
        (*direita) = aux_A->dir;
        free(aux_A);
    }
    else
        aux_D = menorDosMaiores(&(aux_A->esq));

    return aux_D;
}


int cria_ABB(ARVORE *A)
{
    *A = NULL;
}

int ABB_estaVazia (ARVORE A)
{
    return A == NULL;
}

int quantidade_ABB(ARVORE A)
{
    return -1;
}

int insere_ABB  (ARVORE* A, DADO dado)
{
    int result = 0;

    if (ABB_estaVazia(*A))
    {
        (*A) = (NO*)malloc(sizeof(NO));
        (*A)->dado = dado;
        (*A)->esq  = NULL;
        (*A)->dir  = NULL;
        result = 1;
    }
    else
    {
        if (strcmp((*A)->dado.nome, dado.nome) < 0)
            result = insere_ABB( &((*A)->dir), dado);
        else 
        if (strcmp((*A)->dado.nome, dado.nome) > 0)
            result = insere_ABB( &((*A)->esq), dado);   
        else
            result = 0;

    }

    return result;
}

int remove_ABB  (ARVORE* A, DADO* dado)
{
    int result = 0;
    ARVORE aux_A;

    if (ABB_estaVazia(*A))
        result = 0;
    else
    {
        if (strcmp((*A)->dado.nome, dado->nome) < 0)
            result = remove_ABB(&((*A)->dir), dado);
        else
        if (strcmp((*A)->dado.nome, dado->nome) > 0)
            result = remove_ABB(&((*A)->esq), dado);
        else
        {
            *dado = (*A)->dado;
            aux_A = *A;

            if ((*A)->esq == NULL)
            {
                *A = aux_A->dir;
                free(aux_A);
            }
            else
            if ((*A)->dir == NULL)
            {
                *A = aux_A;
                free(aux_A);
            }
            else
                (*A)->dado = maiorDosMenores(&((*A)->esq));

            result = 1;
        }
    }

    return result;
}

int consulta_ABB(ARVORE A, DADO* dado)
{
    int result = 0;

    if (ABB_estaVazia(A))
        result = 0;
    else
    {
        if (strcmp(A->dado.nome, dado->nome) < 0)
            result = consulta_ABB(A->dir, dado);
        else
        if (strcmp(A->dado.nome, dado->nome) > 0)
            result = consulta_ABB(A->esq, dado);
        else
        {
            *dado = A->dado;
            result = 1;
        }
    }
    
    return result;
}

int preOrdem(ARVORE A)
{
    if (!ABB_estaVazia(A))
    {
        printNo(A);
        preOrdem(A->esq);
        preOrdem(A->dir);
    }
}

int emOrdem (ARVORE A)
{
    if (!ABB_estaVazia(A))
    {
        emOrdem(A->esq);
        printNo(A);
        emOrdem(A->dir);
    }
}

int posOrdem(ARVORE A)
{
    if (!ABB_estaVazia(A))
    {
        posOrdem(A->esq);
        emposOrdem(A->dir);
        printNo(A);
    }
}

int mostra_ABB(ARVORE A)
{

}