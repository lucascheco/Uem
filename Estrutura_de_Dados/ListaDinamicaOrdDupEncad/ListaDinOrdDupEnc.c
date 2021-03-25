#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinOrdDupEnc.h"

typedef tipoElem *tipoPonteiro;

void criaLista(tipoLista *l)
{   int i;

    l->quant = 0;
    l->lista_pri = NULL;
    l->lista_ult = NULL;
}

int listaCheia(tipoLista l)
{
    return (0);
}

int listaVazia(tipoLista l)
{
    return (l.quant==0);   /* return (l.lista_pri==NULL) ou (l.lista_ult==NULL); */
}

int quantLista(tipoLista l)
{
    return (l.quant);
}

int buscaLista(tipoLista l, char nome[], tipoPonteiro *ender)
{   int tem_mais;

    (*ender)=NULL;

    if (listaVazia(l))
        return (0);
    else
    {   (*ender)=l.lista_pri;

        tem_mais=(*ender)->prox!=NULL;

        while ((strcmp((*ender)->dado.nome,nome) < 0)&&
               (tem_mais))
        {
            (*ender)=(*ender)->prox;
            tem_mais=(*ender)->prox!=NULL;
        }

        if (strcmp((*ender)->dado.nome,nome)==0)
            return (1);
        else  return (0);
    }

}

int insereLista(tipoLista *l, tipoDado dado)
{   tipoPonteiro ender, aux, ant;

    if (listaCheia(*l))
        return (0);
    else
    {
        if (buscaLista(*l, dado.nome, &ender))
            return (0);
        else
        {
            aux = malloc(sizeof(tipoElem));
            aux->dado=dado;

            if (ender==NULL)
            {
                /* primeira insercao */

                aux->ant=NULL;
                aux->prox=NULL;
                l->lista_pri=aux;
                l->lista_ult=aux;

            }
            else
            {
             if (strcmp(ender->dado.nome,dado.nome)==-1)
             {
                /* inserir no final da lista, apos o ultimo (apontado por ender) */

                ender->prox=aux;
                aux->ant=ender;
                aux->prox=NULL;
                l->lista_ult=aux;
             }
             else
             {
                ant=ender->ant; /* pode ser NULL */
                ender->ant=aux;
                aux->prox=ender;
                aux->ant=ant;

                if (ant!=NULL)
                    ant->prox=aux;
                else l->lista_pri=aux;
             }
            }

            l->quant++;
            return (1);
        }
    }
}

int consultaPorNome(tipoLista l, tipoDado *dado)
{   tipoPonteiro ender;

    if (listaVazia(l))
        return (0);
    else
    {
       if (buscaLista(l, dado->nome, &ender))
       {
           *dado=ender->dado;
           return (1);
       }
       else return (0);
    }
}

int consultaPorPosicao(tipoLista l, int pos, tipoDado *dado)
{   int count;
    tipoPonteiro ender;

    if (listaVazia(l)||(pos>l.quant))
        return (0);
    else
    {
        count=1;
        ender=l.lista_pri;
        while (count<pos)
        {
            count++;
            ender=ender->prox;
        }

        *dado=ender->dado;
        return (1);
    }

}

int removeLista(tipoLista *l, tipoDado *dado)
{   tipoPonteiro ender, ant, prox;

    if (listaVazia(*l))
        return (0);
    else
    {
       if (buscaLista(*l, dado->nome, &ender))
       {
           ant = ender->ant;
           prox = ender->prox;
           *dado=ender->dado;

           if (ant==NULL)
           {
               if (prox==NULL)
               {
                   /* elemento unico que sera removido */
                   l->lista_pri=NULL;
                   l->lista_ult=NULL;
               }
               else
               {
                   prox->ant=NULL;
                   l->lista_pri=prox;
               }
           }
           else
           {
               if (prox==NULL)
               {
                   ant->prox=NULL;
                   l->lista_ult=ant;
               }
               else
               {
                   ant->prox=prox;
                   prox->ant=ant;
               }
           }

           free(ender);
           l->quant--;
           return (1);
       }
       else return (0);
    }
}

int atualizaNomeLista(tipoLista* l, char nomeAnterior[], char nomeNovo[])
{
	if (listaVazia(*l))
        return 0;

    tipoDado aux;
    
    strcpy(aux.nome, nomeAnterior);

    removeLista(l, &aux);

    strcpy(aux.nome, nomeNovo);

    insereLista(l, aux);

    return 1;
}