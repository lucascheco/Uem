#include<stdio.h>
#include<stdlib.h>
#include "listaestligadaordenada.h"

struct no
{
  char info;
  int prox;
};

struct Lista
{
  struct no* vet;
  int prim; 
  int dispo; 
  int qtde; 
  int max; 
};

void debug_lista(const TLista* lista)
{
  printf("\n_____________DEBUG_____________");
  printf("\n|--Indice do primeiro     -> %d|", lista->prim);
  printf("\n|--Indice dos disponiveis -> %d|", lista->dispo);
  printf("\n|_____________________________|\n\n");
}

/*Privadas*/

/*  Essa funcao buscara o indice do "no" armazenado no vetor.
    Caso esteja vazia, retornara falso.
    
    Se a lista nao esta vazia
      Caso o elemento buscado esteja na lista ele retornara verdadeira e nos parametros de referencia
      o indice do elemento e o indice do anterior.
      Caso o elemento buscado nao esteja ele retornara falso e no parametro de referencia o indice do 
      elemento anterior a proxima insercao, ou seja retorna a ultima posicao.

    * Essa funcao sera usada para auxiliar a insercao e remocao. *
*/
int busca_indice(TLista lista, char x, int* indice_atual, int* indice_anterior)
{
  *indice_atual    = lista.prim;
  *indice_anterior = -1;
  
  if (esta_vazia(&lista))
    return 0;
  else
  {
    while (*indice_atual != -1)
    {
      if (lista.vet[*indice_atual].info == x)
        return 1;

      *indice_anterior = *indice_atual;
      *indice_atual    = lista.vet[*indice_atual].prox;
    }

    return 0;
  }
}

int busca_indice_anterior_a_insercao(TLista lista, char x, int* indice_anterior)
{
  int indice_atual = lista.prim;
  *indice_anterior = -1;

  if (esta_vazia(&lista))
    return 0;
  else
  {
    while (indice_atual != lista.dispo)
    { 
      if (lista.vet[indice_atual].info > x)
        return 1;

      *indice_anterior = indice_atual;
      indice_atual = lista.vet[indice_atual].prox;
    }

    return 1;
  }
}

int busca_indice_ultimo(TLista lista, int* indice_ultimo)
{
  if (esta_vazia(&lista))
    return 0;

  int indice = lista.prim;

  while (lista.vet[indice].prox != lista.dispo)
    indice = lista.vet[indice].prox;

  *indice_ultimo = indice;

  return 1;
}

/*Publicas*/
int lista_existe(const TLista* lista)
{
    return lista != NULL;
}

int esta_vazia(const TLista* lista)
{
  return lista->qtde == 0;
}

int esta_cheia(const TLista* lista)
{
  return lista->qtde == lista->max;
}

TLista* cria_lista(int tam)
{
  TLista* list = (TLista *) malloc(sizeof(TLista));
  list->vet = (struct no *) malloc(sizeof(struct no)*tam);

  for(int i = 0; i < tam; i++)
    list->vet[i].prox = i + 1;

  list->vet[tam-1].prox = -1;

  list->qtde = 0; 
  list->dispo = 0; 
  list->prim = -1; 
  
  list->max = tam;

  return list;
}

void imprimir(const TLista* lista)
{
  printf("\nQuantidade: %d", lista->qtde);
  printf("\nImprimindo a Lista: ");
  
  int indice = lista->prim;
  
  while(indice !=- 1)
  {
    printf("%c -> ",lista->vet[indice].info);
    indice = lista->vet[indice].prox;
  }
}

// int inserir(TLista* lista, char x)
// {
//   if (esta_cheia(lista))
//     return 0;
//   else
//   {
//     int indice_atual, indice_anterior;

//     if (busca_indice(*lista, x, &indice_atual, &indice_anterior)) /* Na insercao, a busca retornara o elemento anterior  a insercao. */
//       return 0;
//     else
//     {
//       if (esta_vazia(lista))
//       {
//         lista->prim = lista->dispo;                  /* Nao ira mais mudar, este campo é atualizado somente na primeira insercao e na ultima remocao.*/
//         lista->vet[lista->dispo].info = x;            
//         lista->dispo = lista->vet[lista->dispo].prox;/* Atualizacao da lista de disponiveis */
//       }
//       else
//       {
        
//         int indice_dispo = lista->dispo; 
 
//         lista->dispo = lista->vet[indice_dispo].prox; /* Atualizacao da lista de disponiveis */

//         lista->vet[indice_dispo].prox = lista->vet[indice_anterior].prox; 
//         lista->vet[indice_dispo].info = x;
//         lista->vet[indice_anterior].prox = indice_dispo;
//       }

//       lista->qtde++;
      
//       return 1;
//     }
//   }
// }

int inserir(TLista* lista, char x)
{
  if (esta_cheia(lista))
    return 0;
  else
  {
    int indice_anterior, indice_atual, indice_ultimo;

    /* Atribuimos valores para todos indices acima. */
    indice_atual = lista->dispo;
    busca_indice_anterior_a_insercao(*lista, x, &indice_anterior);
    busca_indice_ultimo(*lista, &indice_ultimo);

    printf("\n-->indice anterior = %d\n", indice_anterior);
    printf("-->indice atual = %d\n", indice_atual);
    printf("--indice ultimo = %d\n\n", indice_ultimo);
    
    if (esta_vazia(lista))
    {
      lista->vet[indice_atual].info = x;

      lista->prim = lista->dispo;
      lista->dispo = lista->vet[indice_atual].prox;
    }
    else 
    {
      lista->vet[indice_atual].info = x;

      if (indice_anterior == -1)
        lista->prim = lista->dispo;
      
      lista->dispo = lista->vet[indice_atual].prox;

      lista->vet[indice_ultimo].prox = lista->vet[indice_atual].prox;
      lista->vet[indice_atual].prox = lista->vet[indice_anterior].prox;
      lista->vet[indice_anterior].prox = indice_atual;

    }

    lista->qtde++;
    
    return 1;
  }
}

int remover (TLista* lista, char x)
{
  if (esta_vazia(lista))
    return 0;
  else
  {
    int indice_anterior, indice_atual, indice_ultimo;
    
    indice_atual = lista->dispo;
    busca_indice_anterior_a_insercao(*lista, x, &indice_anterior);
    busca_indice_ultimo(*lista, &indice_ultimo);

  }
}

int tamanho (const TLista* lista)
{
  return lista->qtde;
}


int acessar(TLista* lista, int pos, char *x)
{

}

int devolver(TLista* lista, int *pos, char x)
{

}

void destroi(TLista* lista)
{

}
