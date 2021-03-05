#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct Lista
{
    char* vet;
    int qtde; 
    int tam; 
};

TLista* cria_lista(int tam)
{
    TLista* lista = (TLista *)malloc(sizeof(TLista));
    lista->vet    = (char *)calloc(tam, sizeof(char));
    lista->tam    = tam;
    lista->qtde   = 0; 

    return lista;
}

int lista_existe(TLista* lista)
{
    return lista != NULL;
}

int lista_vazia(TLista* lista)
{
    if (lista_existe(lista))
        return !lista->qtde;
    else
        return 0;
}

int lista_cheia(TLista* lista, int tam)
{   
    if (lista_vazia(lista))
        return lista->qtde == tam;
    else
        return 0;
}

void destroi(TLista* lista)
{
    free(lista->vet);
    free(lista);
}

int tamanho(TLista* lista)
{
    if (lista_vazia(lista))
        return 0;
    else
        return lista->tam;
}

int quantidade(TLista* lista)
{
        return lista->qtde;
}

void imprimir(TLista* lista)
{
    printf("Lista: ");
    for (int i = 0; i < lista->tam; ++i)
        if (lista->vet[i] == 0)
            printf(" -> ");
        else
            printf("|%c->", lista->vet[i]);
    printf("\n");


    printf("Index: ");
    for (int i = 0; i < lista->tam; ++i)
        printf("|_%d_", i);   

    printf("\n"); 
}

int posicao_ocupada(TLista* lista, int pos)
{
    if (pos < lista->tam)
        return lista->vet[pos] != 0;
    else 
        return 0;
}

int posicaolivre_esquerda(TLista* lista, int pos, int* index_livre)
{
    for (int i = pos; i > -1; --i)
        if (lista->vet[i] == 0)
        {
            *index_livre = i;
            return 1;
        }

    *index_livre = -1;
    
    return 0;
}

int posicaolivre_direita(TLista* lista, int pos, int* index_livre)
{
    for (int i = pos; i < lista->tam - 1 ; ++i)
        if (lista->vet[i] == 0)
        {
            *index_livre = i;
            return 1; 
        }
    
    *index_livre = -1;
    return 0;
}

int inserir(TLista* lista, char c, int pos)
{
    int index;

    if (lista_cheia(lista, lista->tam) || pos > lista->tam) 
        return 0;
    else 
    {
        if (posicao_ocupada(lista, pos))
        {
            if (posicaolivre_direita(lista, pos, &index))
            {
                for (int j = index ; pos <= j - 1; --j)
                {  
                    lista->vet[j] = lista->vet[j - 1];
                    lista->vet[j-1] = 0;
                
                }
            }
            else
            if (posicaolivre_esquerda(lista, pos, &index))
            {
                for (int j = index; j + 1 <= pos; ++j)
                {
                    lista->vet[j] = lista->vet[j + 1];
                    lista->vet[j + 1] = 0; 
                }
            }
            else
                return 0;
        } 
        
        lista->vet[pos] = c;
        lista->qtde++;
        
        return 1;
    }
}

int remover(TLista* lista, int pos)
{
    if (!posicao_ocupada(lista, pos) || lista_vazia(lista))
        return 0;
 
    lista->vet[pos] = 0;
    lista->qtde--;    
    
    return 1;
}

int acessar(TLista* lista, int pos, char* elem)
{
    if (!posicao_ocupada(lista, pos) || lista_vazia(lista))
        return 0;

    *elem = lista->vet[pos];


    return 1;
}

int devolver(TLista* lista, char c, int* pos)
{
    *pos = -1;
    for (int i = 0; i < lista->tam-1; ++i)
        if (lista->vet[i] == c)
        {
            *pos = i;
            return 1;
        }

    return 0;
}
