/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Lista com arrasto, aplicação principal.
    Date:        21/02/2021
************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ListaOrdEncad.h"

LISTA lista;
DADO dado;

void list_lista(LISTA lista);

void printa_dado(DADO dado, int i);

void clean_screen();

int menu()
{   
    int op;
    printf("------------------------------------------\n");
    printf("   PROGRAMA LISTA ORDENADA ENCADEADA\n");
    printf("------------------------------------------\n");

    printf("Menu:\n");
    printf("1 - Criar\n");
    printf("2 - Inserir\n");
    printf("3 - Remover\n");
    printf("4 - Consulta por nome\n");
    printf("5 - Consulta por posicao\n");
    printf("6 - Quantidade\n");
    printf("7 - Listar\n");
    printf("8 - Atualizar\n");
    printf("9 - Sair\n");
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
            criaListaOrd(&lista);
            break;
            
        case 2: 
            if (esta_cheia(lista))
                printf("Erro: Lista esta cheia!\n");
            else
            {
                DADO dado_dentro;
                printf("\nDigite o nome > ");
                fgets(dado_dentro.nome, MAXNOME, stdin);
                printf("Digite o genero> ");
                scanf("%c", &dado_dentro.genero); getchar();
                printf("\nDigite a data de nascimento> ");
                printf("\nDia: ");
                scanf("%d", &(dado_dentro.dnasc.dia)); getchar();
                printf("Mes: ");
                scanf("%d", &(dado_dentro.dnasc.mes)); getchar();
                printf("Ano: ");
                scanf("%d", &(dado_dentro.dnasc.ano)); getchar();
                printf("Digite o  numero do RG> ");
                scanf("%d", &dado_dentro.rg); getchar();

                if (!insere_Lista(&lista, dado_dentro))
                    printf("Erro: Lista cheia ou registro ja existe.\n");
                else
                    printf("Registro inserido com sucesso!\n");

            }

            break;

        case 3: 
            if (esta_vazia(lista))
                printf("Erro: lista esta vazia!\n");
            else
            {
                DADO dado_dentro;
                printf("Digite um nome para retirar>");
                fgets(dado_dentro.nome, MAXNOME, stdin);
                if (!consulta_por_Nome(lista, &dado_dentro))
                    printf("Registro nao existe.\n");
                else
                {
                    remove_Lista(&lista, &dado_dentro);
                    printf("Dado removido:\n");
                    printa_dado(dado_dentro, -1);     
                }
            }

            break;

        case 4: 
            if (esta_vazia(lista))
                printf("Erro: lista esta vazia!\n");
            else
            {
                printf("Digite o nome a ser buscado> ");
                fgets(dado.nome, MAXNOME, stdin);

                if (!consulta_por_Nome(lista, &dado))
                    printf("Registro Nao encontrado!\n");
                else
                    printa_dado(dado, 1);

            }

            break;

        case 5:
            if (esta_vazia(lista))
                printf("Error: lista esta vazia!\n");
            else
            {
                int pos;
                
                printf("Digite a posicao>");
                scanf("%d", &pos);  getchar();

                if (!consulta_por_Pos(lista, pos, &dado))
                    printf("Erro: Posicao invalida!\n");
                else
                    printa_dado(dado, pos);

            }
            
            break;
        
        case 6: 
            printf("O numero de elementos na lista e %d\n", quantidade(lista));
            break;
        
        case 7:
            if (esta_vazia(lista))
                printf("Erro: lista esta vazia!\n");
            else
                list_lista(lista);
            
            break;

        case 8:
            printf("Atualizar lista:\n");
            DADO dado_dentro;
            printf("\nDigite o nome > ");
            fgets(dado_dentro.nome, MAXNOME, stdin);
            printf("Digite o genero> ");
            scanf("%c", &dado_dentro.genero); getchar();
            printf("\nDigite a data de nascimento> ");
            printf("\nDia: ");
            scanf("%d", &(dado_dentro.dnasc.dia)); getchar();
            printf("Mes: ");
            scanf("%d", &(dado_dentro.dnasc.mes)); getchar();
            printf("Ano: ");
            scanf("%d", &(dado_dentro.dnasc.ano)); getchar();
            printf("Digite o  numero do RG> ");
            scanf("%d", &dado_dentro.rg); getchar();

            if (!atualizar(&lista, dado_dentro))
                printf("Dado nao encontrado.\n");
            else
                printf("Dado atualizado.\n");
            
            break;

    }
}

int main()
{   
    int op;

    do
        option(op = menu());
    while (op != 9);

    return 0;
}

void list_lista(LISTA lista)
{
    printf("Elementos:\n");
    int total = quantidade(lista);

    for (int pos = 1; pos <= total; pos++)
    {
        DADO dado_dentro;
        consulta_por_Pos(lista, pos, &dado_dentro);
        printa_dado(dado_dentro, pos);
    }
}

void printa_dado(DADO dado_dentro, int i)
{
    printf("-----------------------------------------\n");
    printf("||||<-Registro %d->||||\n    Nome > %s", i, dado_dentro.nome);
    printf("    Genero: %c\n", dado_dentro.genero);
    printf("    A data de nascimento > %d/%d/%d\n", dado_dentro.dnasc.dia, dado_dentro.dnasc.mes, dado_dentro.dnasc.ano);
    printf("    O numero do RG > %d\n", dado_dentro.rg);
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