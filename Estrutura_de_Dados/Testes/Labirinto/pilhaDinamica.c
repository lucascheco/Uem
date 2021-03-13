#include <stdio.h>
#include <stdlib.h>

/* definição do sentido */

#define nenhum   0  /* indica ponto de partida */
#define esquerdo 1  /* indica sentido esquerdo */
#define direito  2  /* indica sentido direito */
#define frontal  3  /* indica sentido frontal */

/* definição das informações do ponto a ser empilhado */

typedef struct{
    int lin, col,   /* coordenada no labirinto */
        esq,        /* 0 = obstaculo/impedimento, 1 = caminho possível */
        dir,        /* 0 = obstaculo/impedimento, 1 = caminho possível */
        fro,        /* 0 = obstaculo/impedimento, 1 = caminho possível */
        sent_in,    /* 0, 1 ou 2 */
        sent_out,   /* 1, 2 ou 3 */
        tronco;     /* 1 = sim, 0 = não */
} tipoDado;

typedef struct tipoElem
{
    tipoDado dado;
    struct tipoElem *prox;
} tipoElem;

typedef tipoElem *tipoPilha;

void criaPilha(tipoPilha *p)
{
    *p=NULL;
}

int pilhaVazia(tipoPilha p)
{
    return (p==NULL);
}

int pilhaCheia(tipoPilha p)
{
    return (0);
}

int topoPilha(tipoPilha p, tipoDado *topo)
{
    if (pilhaVazia(p))
        return (0);
    {
        *topo=p->dado;
        return (1);
    }
}

int emPilha(tipoPilha *p, tipoDado dado)
{   tipoElem *aux;

    aux=malloc(sizeof(tipoElem));
    aux->dado=dado;
    aux->prox=*p;

    *p=aux;
    return (1);
}

int desemPilha(tipoPilha *p, tipoDado *dado)
{   tipoElem *aux;

    if (pilhaVazia(*p))
        return (0);
    {
        *dado = (*p)->dado;
        aux=*p;
        *p=aux->prox;
        free(aux);
        return(1);
    }
}


