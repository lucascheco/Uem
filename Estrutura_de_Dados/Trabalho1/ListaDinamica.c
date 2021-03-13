/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Lista dinâmica ordenada encadeada, funções.
    Date:        11/03/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinamica.h"

typedef struct sNo *ponteiro;

struct sNo
{
    DADO info;
    ponteiro prox;
};

struct Lista
{
    ponteiro prim;
    int qtde;
    int criada; /* flag de criacao */
};

TLista* cria_lista()
{
    TLista *lista = (TLista *)malloc(sizeof(TLista));
    lista->prim = NULL;
    lista->qtde = 0;
    lista->criada = 1;
    
    return lista;
}

int lista_existe(const TLista* lista)
{
    return lista->criada;
}

int esta_vazia(TLista* lista)
{
    return lista->qtde == 0;
}

int esta_cheia()
{
    return 0;
}

int inserir(TLista* lista, DADO dado)
{
    ponteiro novo = (ponteiro)malloc(sizeof(struct sNo));

    novo->info = dado;
    if (esta_vazia(lista) || strcmp(lista->prim->info.nome, dado.nome) > 0)
    { 
        novo->prox = lista->prim;
        lista->prim = novo;
    }
    else
    {
        ponteiro pos, antes;
        pos = lista->prim;

        while (pos != NULL && strcmp(pos->info.nome, dado.nome) < 0)
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



ponteiro busca_info(TLista* lista, DADO dado, ponteiro* antes, int* i)
{
    ponteiro pos = lista->prim;
    *antes = NULL;
    *i = 1;
    while (pos != NULL)
    {
        if (strcmp(pos->info.nome, dado.nome) == 0)
            return pos;

        *antes = pos;
        pos   = pos->prox;
        
        *i += 1;
    }

    return NULL;
}

int remover(TLista* lista, DADO dado)
{
    if (esta_vazia(lista))
        return 0;
    else
    {
        ponteiro pos, antes;
        int i;
        
        if ((pos = busca_info(lista, dado, &antes, &i)) == NULL)
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


int tamanho(TLista* lista)
{
    return lista->qtde;
}

int consultaPosicao(TLista* lista, int posicao, DADO* dado)
{
    if (esta_vazia(lista) || posicao <= 0 || posicao > lista->qtde)
        return 0;

    ponteiro pos = lista->prim;

    int i = 1;

    while (i++ < posicao)
        pos = pos->prox;

    *dado = pos->info;

    return 1;
}

int consultaNome(TLista* lista, DADO* dado, int* posicao)
{
    ponteiro pos, antes;
    if (esta_vazia(lista))
        return 0;
    else
    {
        int i;
        if ((pos = busca_info(lista, *dado, &antes, &i)) == NULL)
            return 0;

        *dado = pos->info;
        *posicao = i;

        return 1;        
    }
}

int atualiza(TLista* lista, DADO* dado, int posicao)
{
    if (esta_vazia(lista) || posicao <= 0 || posicao > lista->qtde)
        return 0;

    ponteiro pos = lista->prim;

    int i = 1;

    while (i++ < posicao)
        pos = pos->prox;

    printf("Digite o genero> ");
    scanf("%c", &(dado->genero)); getchar();
    printf("\nDigite a data de nascimento> ");
    printf("\nDia: ");
    scanf("%d", &(dado->dnasc.dia)); getchar();
    printf("Mes: ");
    scanf("%d", &(dado->dnasc.mes)); getchar();
    printf("Ano: ");
    scanf("%d", &(dado->dnasc.ano)); getchar();
    printf("Digite o  numero do RG> ");
    scanf("%d", &(dado->rg)); getchar();
    
    printf("\nDigite a profissao> ");
    fgets(dado->profissao, MAXNOME, stdin);
    printf("\nDigite o salario> ");
    scanf("%f", &(dado->salario)); getchar();

    pos->info = *dado;

    return 1;
}

void destroi(TLista* lista)
{
    free(lista);
}


void printa_dado(const DADO* dado, int i)
{
    printf("-----------------------------------------\n");
    printf("||||<-Registro %d->||||\n" ,i+1);
    printf("    Nome > %s",                         dado->nome);
    printf("    Genero > %c\n",                     dado->genero);
    printf("    A data de nascimento > %d/%d/%d\n", dado->dnasc.dia, dado->dnasc.mes, dado->dnasc.ano);
    printf("    O numero do RG > %d\n",             dado->rg);
    printf("    Profissao > %s\n",                  dado->profissao);
    printf("    Salario > %f\n",                    dado->salario);
}

void imprimir(TLista* lista)
{
    printf("\nQuantidade: %d", lista->qtde);
    printf("\nImprimindo a Lista: \n");
    
    ponteiro pos = lista->prim;
    int i = 0;

    while(pos != NULL)
    {
        printa_dado(&(pos->info), i);
        pos = pos->prox;

        i++;
    }
}