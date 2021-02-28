/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Lista encadeada ordenada, tipos abstratos e prtótipos.
    Date:        23/02/2021
************************************************************************************/

#define MAXNOME 75
#define MAXLIST 100
#define TERRA   -1

typedef struct tipoDN
{
    int dia, mes, ano;
} 
DN;

typedef struct dado
{
    char nome[MAXNOME];
    DN dnasc;
    int rg;
    char genero;
}
DADO;

typedef struct elem
{
    DADO dado;
    int prox;
}
ELEM;

typedef struct lista
{
    ELEM lista[MAXLIST];
    int quant;
    int ocupado;
    int livre;
}
LISTA;

/*Publicas*/
void criaListaOrd(LISTA* L);

int esta_cheia(LISTA L);

int esta_vazia(LISTA L);

int quantidade(LISTA L);

int consulta_por_Nome(LISTA L, DADO* dado);

int consulta_por_Pos(LISTA L, int pos, DADO* dado);

int insere_Lista(LISTA* L, DADO dado);

int remove_Lista(LISTA* L, DADO* dado);

int atualizar(LISTA* L, DADO dado_atual);