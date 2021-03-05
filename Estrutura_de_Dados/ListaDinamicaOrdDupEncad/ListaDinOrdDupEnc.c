#include <stdlib.h>
#include "ListaDinOrdDupEnc.h"

int busca_lista(LISTA L, char nome[], point* endereco)
{
    *endereco = NULL;

    if (esta_vazia(L))
        return 0;
    else
    {
        int tem_mais;

        endereco = L.lista_primeira;
        tem_mais = (*endereco->prox != NULL);

        while (strcmp((*ender)->dado.nome, nome)  < 0 && tem_mais)
        {
            /* code */
        }
        
    }
    
}

void criaListaOrd(LISTA* L)
{
    L->quant = 0;
    L->lista_primeira = NULL;
    L->lista_ultimo   = NULL;

}

int esta_cheia(LISTA L)
{
    return 0;
}

int esta_vazia(LISTA L)
{
    return L.quant == 0;
}

int quantidade(LISTA L)
{

}

int consulta_por_Nome(LISTA L, DADO* dado)
{

}

int consulta_por_Pos(LISTA L, int pos, DADO* dado)
{

}

int insere_Lista(LISTA* L, DADO dado)
{

}

int remove_Lista(LISTA* L, DADO* dado)
{

}

int atualizar(LISTA* L, DADO dado_atual)
{

}