/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Árvores Binárias balanceadas, funções.
    Date:        15/04/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVL.h"

/* Funções Pilha */
void criar_Pilha(PILHA *pilha)
{
    *pilha = NULL;
}

int pilha_EstaVazia(PILHA pilha)
{
    return pilha == NULL;
}

int topo(PILHA pilha, ARVORE *top)
{
    if (pilha_EstaVazia(pilha))
        return 0;
    else
    {
        *top = pilha->dado;
        return 1;
    }
}

int insere_Pilha(PILHA *pilha, ARVORE dado)
{
    _pilha *aux;

    aux = (_pilha *)malloc(sizeof(_pilha));
    aux->dado = dado;
    aux->prox = *pilha;

    *pilha = aux;

    return 1;
}

int remove_Pilha(PILHA *pilha, ARVORE *dado)
{
    _pilha *aux;

    if (pilha_EstaVazia(*pilha))
        return 0;
    else
    {

        *dado = (*pilha)->dado;
        aux = *pilha;
        *pilha = aux->prox;

        free(aux);
        return 1;
    }
}

/* Funçõe privadas */
void printNo(ARVORE No)
{
    printf("\nNome: %s RG: %d Idade: %d\n", No->dado.nome, No->dado.RG, No->dado.idade);
}

int balanceiaDirR(ARVORE *raiz)
{
    int diminuiu = 1;
    ARVORE p1, p2, p3;

    switch ((*raiz)->balanco)
    {
    case 0:
        (*raiz)->balanco = 1;
        diminuiu = 0;
        break;

    case -1:
        (*raiz)->balanco = 0;
        break;

    case +1: /* balanco iria para +2 => aplicar rotacao RR ou RL */
        p1 = *raiz;
        p2 = p1->dir;

        if ((p2->balanco == 1) || (p2->balanco == 0))
        { /* realizar RR - r*/
            p1->dir = p2->esq;
            p2->esq = p1;
            (*raiz) = p2;

            if (p2->balanco == 0)
            {
                p1->balanco = 1;
                p2->balanco = -1;
            }
            else
            {
                p1->balanco = 0;
                p2->balanco = 0;
            }
        }
        else
        { /* realizar RL */
            p3 = p2->esq;
            p1->dir = p3->esq;
            p2->esq = p3->dir;
            p3->esq = p1;
            p3->dir = p2;
            (*raiz) = p3;

            if (p3->balanco == 0)
            {
                p1->balanco = 0;
                p2->balanco = 0;
                p3->balanco = 0;
            }
            else if (p3->balanco == -1)
            {
                p1->balanco = 0;
                p2->balanco = 1;
                p3->balanco = 0;
            }
            else
            {
                p2->balanco = 0;
                p1->balanco = -1;
                p3->balanco = 0;
            }
        }

        break;
    }

    return diminuiu;
}

int balanceiaEsqR(ARVORE *raiz)
{
    int cresceu;
    ARVORE p1, p2, p3;

    switch ((*raiz)->balanco)
    {
    case 0:
        (*raiz)->balanco = -1;
        cresceu = 1;
        break;

    case -1: /* balanco iria para -2 => aplicar rotacao LL ou LR */
        p1 = *raiz;
        p2 = p1->esq;

        if (p2->balanco == -1)
        { /* realizar LL */
            p1->esq = p2->dir;
            p2->dir = p1;
            (*raiz) = p2;
            p1->balanco = 0;
            p2->balanco = 0;
            cresceu = 0;
        }
        else
        { /* realizar LR */
            p3 = p2->dir;
            p1->esq = p3->dir;
            p2->dir = p3->esq;
            p3->esq = p1;
            p3->dir = p2;
            (*raiz) = p3;

            if (p3->balanco == 0)
            {
                p1->balanco = 0;
                p2->balanco = 0;
                p3->balanco = 0;
            }
            else if (p3->balanco == 1)
            {
                p1->balanco = 0;
                p2->balanco = -1;
                p3->balanco = 0;
            }
            else
            {
                p1->balanco = 1;
                p2->balanco = 0;
                p3->balanco = 0;
            }
        }

        cresceu = 0;
        break;

    case +1:
        (*raiz)->balanco = 0;
        cresceu = 0;
        break;
    }

    return cresceu;
}

DADO maiorDosMenores(ARVORE *esquerda, int *diminuiu)
{
    ARVORE aux_A;
    DADO aux_D;

    aux_A = *esquerda;

    if (AVL_estaVazia((*esquerda)->dir))
    {
        aux_D = aux_A->dado;
        (*esquerda) = aux_A->esq;
        free(aux_A);
        *diminuiu = 1;
    }
    else
    {
        aux_D = maiorDosMenores(&(aux_A->dir), diminuiu);

        if (*diminuiu)
            *diminuiu = balanceiaEsqR(esquerda);
    }
    return aux_D;
}

DADO menorDosMaiores(ARVORE *direita, int *diminuiu)
{
    ARVORE aux_A;
    DADO aux_D;

    aux_A = *direita;

    if (AVL_estaVazia((*direita)->esq))
    {
        aux_D = aux_A->dado;
        (*direita) = aux_A->dir;
        free(aux_A);
    }
    else
    {
        aux_D = menorDosMaiores(&(aux_A->esq), diminuiu);

        if (*diminuiu)
            *diminuiu = balanceiaDirR(direita);
    }

    return aux_D;
}

int balanceiaDir(ARVORE *raiz)
{
    int cresceu;
    ARVORE p1, p2, p3;

    switch ((*raiz)->balanco)
    {
    case 0:
        (*raiz)->balanco = 1;
        cresceu = 1;
        break;

    case -1:
        (*raiz)->balanco = 0;
        cresceu = 0;
        break;

    case +1: /* balanco iria para +2 => aplicar rotacao RR ou RL */
        p1 = *raiz;
        p2 = p1->dir;

        if (p2->balanco == 1)
        { /* realizar RR */
            p1->dir = p2->esq;
            p2->esq = p1;
            (*raiz) = p2;
            p1->balanco = 0;
            p2->balanco = 0;
            cresceu = 0;
        }
        else
        { /* realizar RL */
            p3 = p2->esq;
            p1->dir = p3->esq;
            p2->esq = p3->dir;
            p3->esq = p1;
            p3->dir = p2;
            (*raiz) = p3;

            if (p3->balanco == 0)
            {
                p1->balanco = 0;
                p2->balanco = 0;
                p3->balanco = 0;
            }
            else if (p3->balanco == -1)
            {
                p1->balanco = 0;
                p2->balanco = 1;
                p3->balanco = 0;
            }
            else
            {
                p2->balanco = 0;
                p1->balanco = -1;
                p3->balanco = 0;
            }
        }

        cresceu = 0;
        break;
    }

    return (cresceu);
}

int balanceiaEsq(ARVORE *raiz)
{
    int cresceu;
    ARVORE p1, p2, p3;

    switch ((*raiz)->balanco)
    {
    case 0:
        (*raiz)->balanco = -1;
        cresceu = 1;
        break;

    case -1: /* balanco iria para -2 => aplicar rotacao LL ou LR */
        p1 = *raiz;
        p2 = p1->esq;

        if (p2->balanco == -1)
        { /* realizar LL */
            p1->esq = p2->dir;
            p2->dir = p1;
            (*raiz) = p2;
            p1->balanco = 0;
            p2->balanco = 0;
            cresceu = 0;
        }
        else
        { /* realizar LR */
            p3 = p2->dir;
            p1->esq = p3->dir;
            p2->dir = p3->esq;
            p3->esq = p1;
            p3->dir = p2;
            (*raiz) = p3;

            if (p3->balanco == 0)
            {
                p1->balanco = 0;
                p2->balanco = 0;
                p3->balanco = 0;
            }
            else if (p3->balanco == 1)
            {
                p1->balanco = 0;
                p2->balanco = -1;
                p3->balanco = 0;
            }
            else
            {
                p1->balanco = 1;
                p2->balanco = 0;
                p3->balanco = 0;
            }
        }

        cresceu = 0;
        break;

    case +1:
        (*raiz)->balanco = 0;
        cresceu = 0;
        break;
    }

    return cresceu;
}

int cria_AVL(ARVORE *A)
{
    *A = NULL;
}

int AVL_estaVazia(ARVORE A)
{
    return A == NULL;
}

int quantidade_AVL(ARVORE A)
{
    PILHA pilha1, pilha2;
    ARVORE auxiliar;
    int quant = 0;

    if (AVL_estaVazia(A))
        return quant;

    criar_Pilha(&pilha1);
    criar_Pilha(&pilha2);

    insere_Pilha(&pilha1, A);

    do
    {
        remove_Pilha(&pilha1, &auxiliar);

        if (auxiliar != NULL)
        {
            quant++;
            insere_Pilha(&pilha2, auxiliar->esq);
            insere_Pilha(&pilha2, auxiliar->dir);
        }

        if (pilha_EstaVazia(pilha1))
        {
            while (!pilha_EstaVazia(pilha2))
            {
                remove_Pilha(&pilha2, &auxiliar);
                insere_Pilha(&pilha1, auxiliar);
            }
        }

    } while (!pilha_EstaVazia(pilha1));

    return quant;
}

int _insere_AVL(ARVORE *A, DADO dado, int *cresceu)
{
    int result;

    if (AVL_estaVazia(*A))
    { /* insercao do primeiro elemento */
        (*A) = (NO *)malloc(sizeof(NO));
        (*A)->dado = dado;
        (*A)->esq = NULL;
        (*A)->dir = NULL;
        (*A)->balanco = 0;
        *cresceu = 1;
        result = 1;
    }
    else if (strcmp((*A)->dado.nome, dado.nome) < 0)
    { /* insere na subarvore a direita */
        result = _insere_AVL(&((*A)->dir), dado, cresceu);

        if (cresceu)
            *cresceu = balanceiaDir(A);
    }
    else if (strcmp((*A)->dado.nome, dado.nome) > 0)
    { /* insere na subarvore a esquerda */
        result = _insere_AVL(&((*A)->esq), dado, cresceu);

        if (cresceu)
            *cresceu = balanceiaEsq(A);
    }
    else
        result = 0;

    return result;
}

int insere_AVL(ARVORE *A, DADO dado)
{
    int cresceu = 0;
    return _insere_AVL(A, dado, &cresceu);
}

int _remove_AVL(ARVORE *A, DADO *dado, int *diminuiu)
{
    int result = 0;
    ARVORE aux_A;

    if (AVL_estaVazia(*A))
        result = 0;
    else
    {
        if (strcmp((*A)->dado.nome, dado->nome) < 0)
        {
            result = _remove_AVL(&((*A)->dir), dado, diminuiu);

            if (*diminuiu)
                *diminuiu = balanceiaEsqR(A);
        }
        else if (strcmp((*A)->dado.nome, dado->nome) > 0)
        {
            result = _remove_AVL(&((*A)->esq), dado, diminuiu);

            if (*diminuiu)
                *diminuiu = balanceiaDirR(A);
        }
        else
        {
            *dado = (*A)->dado;
            aux_A = *A;

            if ((*A)->esq == NULL)
            {
                *A = aux_A->dir;
                free(aux_A);
                *diminuiu = 1;
            }
            else if ((*A)->dir == NULL)
            {
                *A = aux_A;
                free(aux_A);
                *diminuiu = 1;
            }
            else
            {
                (*A)->dado = maiorDosMenores(&((*A)->esq), diminuiu);

                if (*diminuiu)
                    *diminuiu = balanceiaDirR(A);
            }
            result = 1;
        }
    }

    return result;
}

int remove_AVL(ARVORE *A, DADO *dado)
{
    int diminuiu = 0;

    return _remove_AVL(A, dado, &diminuiu);
}

int consulta_AVL(ARVORE A, DADO *dado)
{
    int result = 0;

    if (AVL_estaVazia(A))
        result = 0;
    else
    {
        if (strcmp(A->dado.nome, dado->nome) < 0)
            result = consulta_AVL(A->dir, dado);
        else if (strcmp(A->dado.nome, dado->nome) > 0)
            result = consulta_AVL(A->esq, dado);
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
    if (!AVL_estaVazia(A))
    {
        printNo(A);
        preOrdem(A->esq);
        preOrdem(A->dir);
    }
}

int emOrdem(ARVORE A)
{
    if (!AVL_estaVazia(A))
    {
        emOrdem(A->esq);
        printNo(A);
        emOrdem(A->dir);
    }
}

int posOrdem(ARVORE A)
{
    if (!AVL_estaVazia(A))
    {
        posOrdem(A->esq);
        posOrdem(A->dir);
        printNo(A);
    }
}

int mostra_AVL(ARVORE A)
{
    PILHA pilha1, pilha2;
    ARVORE auxiliar;

    if (AVL_estaVazia(A))
        return 0;

    criar_Pilha(&pilha1); // null
    criar_Pilha(&pilha2); // 5 null 15 19 null null null 56

    insere_Pilha(&pilha1, A);

    do
    {
        remove_Pilha(&pilha1, &auxiliar);

        if (auxiliar != NULL)
        {
            printf("%s ", auxiliar->dado.nome); // 38 22*50 12*27*null*60 7*18*null*30*54

            insere_Pilha(&pilha2, auxiliar->esq);
            insere_Pilha(&pilha2, auxiliar->dir);
        }
        else
            printf("NULL ");

        if (pilha_EstaVazia(pilha1)) /* Controla cada nível, se ela esta vazia pula de linha e insere os filhos do dado anterior na p1 */
        {                            /* Se ela está com algum elemento repete-se o dowhile */
            while (!pilha_EstaVazia(pilha2))
            {
                remove_Pilha(&pilha2, &auxiliar); /* ao retirar-mos da p2 retiramos o elemento da direita assim ao inserir-mos na p1 ele */
                insere_Pilha(&pilha1, auxiliar);  /* fica abaixo e ao remover-mos para impressao retiramos o da esquerda. */
            }

            printf("\n");
        }

    } while (!pilha_EstaVazia(pilha1));

    return 1;
}
