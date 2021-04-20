/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Árvores Binárias, funções.
    Date:        25/03/2021
************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

/* Funções Pilha */
void criar_Pilha(PILHA* pilha)
{
    *pilha = NULL;    
}

int pilha_EstaVazia(PILHA pilha)
{
    return pilha == NULL;
}

int topo(PILHA pilha, NOARVORE* top)
{
    if (pilha_EstaVazia(pilha))
        return 0;
    else
    {
        *top = pilha->dado;
        return 1;
    }
}

int insere_Pilha(PILHA* pilha, NOARVORE dado)
{
    _pilha* aux;

    aux = (_pilha*)malloc(sizeof(_pilha));
    aux->dado = dado;
    aux->prox = *pilha;

    *pilha = aux;

    return 1;
}

int remove_Pilha(PILHA* pilha, NOARVORE* dado)
{
    _pilha* aux;

    if (pilha_EstaVazia(*pilha))
        return 0;
    else
    {
    
        *dado  = (*pilha)->dado;
        aux    = *pilha;
        *pilha = aux->prox;

        free(aux);
        return 1;
    }
}

/* Funções Privadas */
void printNo(NOARVORE No)
{
    printf("\nNome: %s RG: %d Idade: %d\n", No->dado.nome, No->dado.RG, No->dado.idade);
}

DADO maiorDosMenores(NOARVORE* esquerda)
{
    NOARVORE anterior, proximo;
    DADO dadoAuxiliar;

    anterior = NULL;
    proximo  = *esquerda;

    while (proximo->dir != NULL)
    {
        anterior = proximo;
        proximo  = proximo->dir;
    }

    dadoAuxiliar = proximo->dado;
    
    return dadoAuxiliar;
}

DADO menorDosMaiores(NOARVORE* direita)
{
    NOARVORE anterior, proximo;
    DADO dadoAuxiliar;

    anterior = NULL;
    proximo  = *direita;

    while (proximo->esq != NULL)
    {
        anterior = proximo;
        proximo  = proximo->esq;
    }

    dadoAuxiliar = proximo->dado;
    
    return dadoAuxiliar;
}

/* Funções Árvore Iterativa */
int cria_ABB(ARVORE *A)
{
    A->quant = 0;
    A->raiz  = NULL; 
}

int ABB_estaVazia(ARVORE A)
{
    return A.raiz == NULL;
}

int ABB_estaCheia(ARVORE A)
{
    return 0;
}

int quantidade_ABB(ARVORE A)
{
    return A.quant;
}

int insere_ABB(ARVORE* A, DADO dado)
{
    NOARVORE anterior, proximo, auxiliar;
    int sentido = 0;

    auxiliar = (NO*)malloc(sizeof(NO));
    
    auxiliar->dado = dado;
    auxiliar->dir  = NULL;
    auxiliar->esq  = NULL;

    if (ABB_estaVazia(*A))
        A->raiz = auxiliar;
    else
    {
        anterior = NULL;
        proximo  = A->raiz;

        while (proximo != NULL)
        {
            anterior = proximo;

            if (strcmp(proximo->dado.nome, dado.nome) < 0)
            {
                sentido = 1;
                proximo = proximo->dir;
            }
            else
            if (strcmp(proximo->dado.nome, dado.nome) > 0)
            {
                sentido = -1;
                proximo = proximo->esq;
            }
            else
            {
                free (auxiliar);
                return 0;
            }
        }
        
        if (sentido == 1)
            anterior->dir = auxiliar;
        else 
            anterior->esq = auxiliar;
    }

    A->quant++;
    
    return 1;
}

int remove_ABB(ARVORE* A, DADO* dado)
{
    NOARVORE anterior, proximo;
    int i = 0;
    int sentido = 0, sentidoSubArvore = 0;

    if (ABB_estaVazia(*A))
        return 0;
    
    anterior = NULL;
    proximo  = A->raiz;

    while (proximo != NULL)
    {
        if (strcmp(proximo->dado.nome, dado->nome) < 0)
        {
            if (i == 0)
                sentidoSubArvore = 1;

            sentido  = 1;
            anterior = proximo;
            proximo  = proximo->dir;
        }
        else
        if (strcmp(proximo->dado.nome, dado->nome) > 0)
        {
            if (i == 0)
                sentidoSubArvore = -1;

            sentido  = -1;
            anterior = proximo;
            proximo  = proximo->esq;
        }
        else
        {
            *dado = proximo->dado;

            if (proximo->esq == NULL)
            {
                if (anterior == NULL)
                    A->raiz = proximo->dir;
                else
                {
                    if (sentido == 1)
                        anterior->dir = proximo->dir;
                    else
                        anterior->esq = proximo->dir;
                }
                free(proximo);
            }
            else
            if (proximo->dir == NULL)
            {
                if (anterior == NULL)
                    A->raiz = proximo->esq;
                else
                {
                    if (sentido == 1)
                        anterior->dir = proximo->esq;
                    else
                        anterior->esq = proximo->esq;
                }
                free(proximo);
            }
            else
                if (sentidoSubArvore  == 1)
                    proximo->dado = menorDosMaiores(&(proximo->dir));
                else
                    proximo->dado = maiorDosMenores(&(proximo->esq));
            

            i++;

            A->quant--;
            return 1;
        }
    }

    return 0;
}

int consulta_ABB(ARVORE A, DADO* dado)
{
    NOARVORE anterior, proximo;

    if (ABB_estaVazia(A))
        return 0;
    else
    {
        anterior = NULL;
        proximo = A.raiz;

        while (proximo != NULL)
        {
            anterior = proximo;
            
            if (strcmp(proximo->dado.nome, dado->nome) < 0)
                proximo = proximo->dir;
            else
            if (strcmp(proximo->dado.nome, dado->nome) > 0)
               proximo = proximo->esq;
            else
            {
                *dado = proximo->dado;
                return 1;
            } 
        }
        
        return 0;
    }
}

int preOrdem(ARVORE A)
{
    NOARVORE noAuxiliar = A.raiz;

    PILHA pilha;

    if (ABB_estaVazia(A))
        return 0;

    criar_Pilha(&pilha);


    insere_Pilha(&pilha, noAuxiliar);

    while (!pilha_EstaVazia(pilha))
    {
        remove_Pilha(&pilha, &noAuxiliar);
        
        printNo(noAuxiliar);

        if (noAuxiliar->dir != NULL)
            insere_Pilha(&pilha, noAuxiliar->dir);

        if (noAuxiliar->esq != NULL)
            insere_Pilha(&pilha, noAuxiliar->esq);
    }
    
}

int emOrdem(ARVORE A)
{
    NOARVORE noAuxiliar = A.raiz;

    PILHA pilha;

    if (ABB_estaVazia(A))
        return 0;

    criar_Pilha(&pilha);

    while (noAuxiliar != NULL)
    {
        while (noAuxiliar != NULL)
        {
            if (noAuxiliar->dir != NULL)
                insere_Pilha(&pilha, noAuxiliar->dir);
            
            insere_Pilha(&pilha, noAuxiliar);

            noAuxiliar = noAuxiliar->esq;
        }

        remove_Pilha(&pilha, &noAuxiliar);

        while (!pilha_EstaVazia(pilha) && noAuxiliar->dir == NULL)
        {
            printNo(noAuxiliar);
            remove_Pilha(&pilha, &noAuxiliar);
        }

        printNo(noAuxiliar);

        if (!pilha_EstaVazia(pilha))
            remove_Pilha(&pilha, &noAuxiliar);
        else
            noAuxiliar = NULL;
    }

    return 1;
}




int posOrdem(ARVORE A)
{
    PILHA pilha;
    NOARVORE noAuxiliar1, noAuxiliar2;
    int acabou = 0;

    if (ABB_estaVazia(A))
        return 0;
    
    noAuxiliar1 = A.raiz;
    noAuxiliar2 = A.raiz;
    criar_Pilha(&pilha);

    while (noAuxiliar1 != NULL)
    {
        for (; noAuxiliar1->esq != NULL; noAuxiliar1 = noAuxiliar1->esq)
            insere_Pilha(&pilha, noAuxiliar1);
        
        while (noAuxiliar1 != NULL && (noAuxiliar1->dir == NULL) || noAuxiliar1->dir == noAuxiliar2)
        {
            printNo(noAuxiliar1);
            noAuxiliar2 = noAuxiliar1;

            if (pilha_EstaVazia(pilha))
                return 1;
            
            remove_Pilha(&pilha, &noAuxiliar1);
        }

        insere_Pilha(&pilha, noAuxiliar1);
        noAuxiliar1 = noAuxiliar1->dir;
    }
    
    return 1;
}

int consultaPai(ARVORE A, DADO* dado)
{
    NOARVORE pai, anterior, proximo;

    if (ABB_estaVazia(A))
        return 0;
    else
    {
        anterior = pai = NULL;
        proximo = A.raiz;

        if (!strcmp(proximo->dado.nome, dado->nome))
            return 0;
        
        while (proximo != NULL)
        {
            pai = anterior;
            anterior = proximo;
            
            if (strcmp(proximo->dado.nome, dado->nome) < 0)
                proximo = proximo->dir;
            else
            if (strcmp(proximo->dado.nome, dado->nome) > 0)
               proximo = proximo->esq;
            else
            {
                *dado = pai->dado;
                return 1;
            } 
        }
        
        return 0;
    }
}

int consultaAscendente(ARVORE A, DADO* dado, int nivel)
{

    if (ABB_estaVazia(A))
        return 0;

    int i = 1;
    consultaPai(A, dado);

    while (dado != NULL && i < nivel)
    {
        consultaPai(A, dado);
        i++;
    }

    return 1;
}

int mostra_ABB(ARVORE A)
{
    PILHA pilha1, pilha2;
    NOARVORE auxiliar;

    if (ABB_estaVazia(A))
        return 0;

    criar_Pilha(&pilha1); // null  
    criar_Pilha(&pilha2); // 5 null 15 19 null null null 56

    insere_Pilha(&pilha1, A.raiz);
    
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
                insere_Pilha(&pilha1,  auxiliar); /* fica abaixo e ao remover-mos para impressao retiramos o da esquerda. */
            }
            
            printf("\n");
        }

    } while (!pilha_EstaVazia(pilha1));

    return 1;
}

/* Mostrar árvore com fila */
// int mostra_ABB2(ARVORE A)
// {
//     FILA fila;
//     NOARVORE auxiliar;
//     int flag = -1;

//     if (ABB_estaVazia(A))
//         return 0;

//     criar_Fila(&fila);

//     insere_Fila(&fila, A.raiz);
//     insere_Fila(&fila, flag);
    
//     do
//     {
//         remove_Fila(&fila, &auxiliar);

//         if (auxiliar != flag)
//         {
//             if (auxiliar != NULL)
//             {
//                 printf("%s ", auxiliar->dado);

//                 insere_Fila(&fila, auxiliar->esq);
//                 insere_Fila(&fila, auxiliar->dir);
//             }
//             else
//                 printf("NULL\n");
//         }
//         else
//         {
//             if (!fila_EstaVazia(fila))
//             {
//                 print("\n");
//                 insere_Fila(&fila, flag);
//             }
//         }

//     } while (!fila_EstaVazia(fila));

//     return 1;
// }

/*TESTE
    Inserir -> Lucas Joao Talita Kaka Xena Vania

    pre -> lucas, joao, kaka, talita, xena vania
    em  -> joao, kaka, lucas, talita, vania, xena
    pos -> kaka, joao, vania, xena, talita, lucas

*/