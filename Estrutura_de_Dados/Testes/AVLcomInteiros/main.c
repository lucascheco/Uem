/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Árvores Binárias balanceadas, aplicação principal.
    Date:        15/04/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVL.h"

ARVORE arvore;
DADO dado, dado_dentro;

void printa_dado(DADO dado, int i);

void clean_screen();

int menu()
{
    int op;
    printf("--------------------------\n");
    printf("      PROGRAMA AVL\n");
    printf("--------------------------\n");

    printf("Menu:\n");
    printf("1  - Criar \n");
    printf("2  - Inserir\n");
    printf("3  - Remover\n");
    printf("4  - Consulta\n");
    printf("5  - Quantidade\n");
    printf("6  - Pre-Ordem\n");
    printf("7  - Em-Ordem\n");
    printf("8  - Pos-Ordem\n");
    printf("9  - Mostra AVL\n");
    printf("10 - Sair\n");
    printf("> ");

    scanf("%d", &op);
    getchar();

    clean_screen();

    return (op);
}

void option(int op)
{
    switch (op)
    {
    case 1:
        cria_AVL(&arvore);
        break;

    case 2:
        printf("\nDigite o numero > ");
        scanf("%d", &dado_dentro.numero);
        getchar();

        if (!insere_AVL(&arvore, dado_dentro))
            printf("Erro: Registro ja existe.\n");
        else
            printf("Registro inserido com sucesso!\n");

        break;

    case 3:
        if (AVL_estaVazia(arvore))
            printf("Erro: Arvore esta vazia!\n");
        else
        {
            printf("Digite um numero para retirar>");
            scanf("%d", &dado_dentro.numero); getchar();

            if (!consulta_AVL(arvore, &dado_dentro))
                printf("Registro nao existe.\n");
            else
            {
                remove_AVL(&arvore, &dado_dentro);
                printf("Dado removido:\n");
                printa_dado(dado_dentro, -1);
            }
        }

        break;

    case 4:
        if (AVL_estaVazia(arvore))
            printf("Erro: lista esta vazia!\n");
        else
        {
            printf("Digite o numero a ser buscado> ");
            scanf("%d", &dado_dentro.numero); getchar();

            if (!consulta_AVL(arvore, &dado))
                printf("Registro Nao encontrado!\n");
            else
                printa_dado(dado, 1);
        }

        break;

    case 5:
        if (AVL_estaVazia(arvore))
            printf("Error: Arvore esta vazia!\n");
        else
            printf("Quantidade > %d\n\n", quantidade_AVL(arvore));

        break;

    case 6:
        if (!preOrdem(arvore))
            printf("Erro: Arvore vazia!\n");

        break;

    case 7:
        if (!emOrdem(arvore))
            printf("Erro: Arvore vazia!\n");

        break;

    case 8:
        if (!posOrdem(arvore))
            printf("Erro: Arvore vazia!\n");

        break;

    case 9:
        if (!mostra_AVL(arvore))
            printf("Erro: Arvore vazia!\n");

        break;
    }
}

int main()
{
    int op;

    do
        option(op = menu());
    while (op != 10);

    return 0;
}

void printa_dado(DADO dado_dentro, int i)
{
    printf("-----------------------------------------\n");
    printf("||||<-Registro %d->||||\n", i);
    printf("    Numero > %d\n", dado_dentro.numero);
}

void clean_screen()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
}
