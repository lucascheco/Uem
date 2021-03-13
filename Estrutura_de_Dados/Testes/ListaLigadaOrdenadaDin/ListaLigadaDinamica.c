#include <stdio.h>
#include <stdlib.h>
#include "ListaLigadaDinamica.h"

typedef struct sNo *ponteiro;

struct sNo
{
    char info;
    ponteiro prox;
};

struct Lista
{
    ponteiro prim;
    int qtde;
};

TLista* cria_lista()
{
    TLista *lista = (TLista *)malloc(sizeof(TLista));
    lista->prim = NULL;
    lista->qtde = 0;
    
    return lista;
}

int esta_vazia(TLista* lista)
{
    return lista->qtde == 0;
}

int esta_cheia()
{
    return 0;
}

int inserir(TLista *lista, char x)
{
    ponteiro novo = (ponteiro)malloc(sizeof(struct sNo));

    novo->info = x;
    if (esta_vazia(lista) || lista->prim->info > x)
    { 
        novo->prox = lista->prim;
        lista->prim = novo;
    }
    else
    {
        ponteiro pos, antes;
        pos = lista->prim;
        while (pos != NULL && pos->info < x)
        {
            antes = pos;
            pos   = pos->prox;
        }
        novo->prox = pos;
        antes->prox = novo;
    }
    lista->qtde++;
    return 1;
}
int devolver(TLista *list, char x, int *pos)
{

}

ponteiro busca_info(TLista* lista, char x, ponteiro* antes)
{
    ponteiro pos = lista->prim;
    *antes = NULL;
    
    while (pos != NULL)
    {
        if (pos->info == x)
            return pos;

        *antes = pos;
        pos   = pos->prox;
    }

    return NULL;
}

int remover(TLista *lista, char x)
{
    if (esta_vazia(lista))
        return 0;
    else
    {
        ponteiro pos, antes;
        
        if ((pos = busca_info(lista, x, &antes)) == NULL)
            return 0;
        else
        {   
            if (antes == NULL)
                lista->prim = pos->prox;
            else
                antes->prox = pos->prox;   
            
        }    
        free(pos);
        lista->qtde--;

        return 1;
    }
}

void imprimir(TLista *lista)
{
    printf("\nQuantidade: %d", lista->qtde);
    printf("\nImprimindo a Lista: ");
    
    ponteiro pos = lista->prim;
    
    while(pos != NULL)
    {
        printf("%c -> ", pos->info);
        pos = pos->prox;
    }
}

int tamanho(TLista *lista)
{
    return lista->qtde;
}

int acessar(TLista *lista, int pos, char *x)
{

}

void destroi(TLista *lista)
{
    ponteiro aux = lista->prim;

    ponteiro auxprox = lista->prim->prox;

    while (auxprox != NULL)
    {
        free(aux);
        aux     = auxprox->prox;
        auxprox = aux->prox;
    }

    free(aux);

    free(lista);
}
