#include<stdio.h>
#include<stdlib.h>
#include "ListaDinDuplamenteEncadeada.h"

/*5 (A)*/////////////////////////////////////////////
typedef struct sNo* ponteiro;

struct sNo
{
  int info;
  ponteiro prox, ant;
};

struct Lista
{
  ponteiro prim, ult;
  int qtde;
};
/////////////////////////////////////////////////////

TLista* cria_lista (int tam)
{
  TLista * list = (TLista *) malloc(sizeof(TLista));

  list->prim  = NULL;
  list->ult   = NULL;
  list->qtde  = 0;

  return list;
}

int inserir(TLista* lista, int x)
{
  ponteiro novo;
  novo = (ponteiro)malloc(sizeof(struct sNo));
  novo->info = x;

  if (lista->qtde == 0)
  {
    novo->ant   = NULL;
    novo->prox  = NULL;
    lista->prim = novo;
    lista->ult  = novo;
  }
  else if (lista->prim->info > x)
  { 
    novo->ant = NULL;
    novo->prox = lista->prim;
    lista->prim = novo;
  }
  else if (lista->ult->info < x)
  { 
  // <-|A|-><-|C|-><-|G|-><-|H|->
  // <-|A|-><-|C|-><-|G|-><-|H|-><-|Z|->
    novo->prox = NULL;
    novo->ant = lista->ult; 
    lista->ult->prox = novo;
    lista->ult = novo;
  } 
  else
  {
    ponteiro pos, antes;
    pos = lista->prim;
  // <-|A|->       <-|G|-><-|H|->   
  // <-|A|-><-|C|-><-|G|-><-|H|->

    while (pos->prox->info < x)
    {
      antes = pos;
      pos   = pos->prox;
    }
    antes->prox = novo;
    pos->ant = novo;
    
    novo->ant = antes;
    novo->prox = pos;
  }

  lista->qtde++;
  return 1;
}

int tamanho (TLista* lista)
{
  return lista->qtde;
}

void imprimir(TLista* lista)
{
  printf("\nQuantidade: %d", lista->qtde);
  printf("\nImprimindo a Lista: ");
  printf("Primeiro-> %c\n", lista->prim->info);
  printf("Ultimo-> %c\n\n", lista->ult->info);
  
  ponteiro pos = lista->prim;
  
  while(pos != NULL)
  {
    printf("%c -> ", pos->info);
    pos = pos->prox;
  }
}

int remover(TLista* lista, int x)
{
  if (lista == NULL)
    return 0;

  struct sNo *aux = lista->prim;

  while (aux != NULL && aux->info != x)
    aux = aux->prox;
  
  if (aux == NULL)
    return 0;

  if (aux->ant == NULL)
    lista->prim = aux->prox;
  else
    aux->ant->prox = aux->prox;

  if (aux->prox != NULL)
    aux->prox->ant = aux->ant;

  lista->qtde--;
  free(aux);
  return 1;
}

int acessar(TLista* lista, int pos, int *x)
{

}

int devolver(TLista* list, int x, int *pos)
{

}

void destroi(TLista* lista)
{

}
