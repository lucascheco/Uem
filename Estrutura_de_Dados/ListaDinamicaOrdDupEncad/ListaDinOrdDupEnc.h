
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxNome 75


typedef struct tipoDN
{
    int dia, mes, ano;
} tipoDN;

typedef struct tipoDado
{
    char nome[maxNome];
    tipoDN dnasc;
    int rg;
} tipoDado;

typedef struct tipoElem
{
    tipoDado dado;
    struct tipoElem *prox;
    struct tipoElem *ant;
} tipoElem;

typedef tipoElem *tipoPonteiro;

typedef struct tipoLista
{
    tipoPonteiro lista_pri, lista_ult;
    int quant;

} tipoLista;

void criaLista(tipoLista *l);

int listaCheia(tipoLista l);

int listaVazia(tipoLista l);

int quantLista(tipoLista l);

int insereLista(tipoLista *l, tipoDado dado);

int consultaPorNome(tipoLista l, tipoDado *dado);

int consultaPorPosicao(tipoLista l, int pos, tipoDado *dado);

int removeLista(tipoLista *l, tipoDado *dado);

int atualizaNomeLista(tipoLista* l, char nomeAnterior[], char nomeNovo[]);
