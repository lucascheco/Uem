/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Lista dinâmica ordenada encadeada, aplicação principal.
    Date:        11/03/2021
************************************************************************************/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "ListaDinamica.h"

TLista *lista = NULL;

void app(int op);
int menu();

void clean_screen()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
}

int main()
{
    int op;

    do
        app(op = menu());
    while (op != 9);

    return 0;
}

int menu()
{
    int op;
    printf("------------------------------------\n");
    printf("       PROGRAMA LISTA DINAMICA\n");
    printf("------------------------------------\n\n");

    printf("Selecione uma opcao:\n");
    printf("1-Criar Lista\n");
    printf("2-Inserir\n");
    printf("3-Remover\n");
    printf("4-Tamanho\n");
    printf("5-ConsultaPosicao\n");
    printf("6-ConsultaNome\n");
    printf("7-Imprimir\n");
    printf("8-Atualiza\n");
    printf("9-Exit\n");
    printf(">>>");

    scanf("%d", &op);
    getchar();
    clean_screen();

    return op;
}

void app(int op)
{
    
    DADO dado_dentro;
    int pos, tam;
    char c;

    switch (op)
    {
    case 1:
        lista = cria_lista();

        break;

    case 2:
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

        printf("\nDigite a profissao> ");
        fgets(dado_dentro.profissao, MAXNOME, stdin);
        printf("\nDigite o salario> ");
        scanf("%f", &dado_dentro.salario); getchar();

        if (!inserir(lista, dado_dentro))
        {
            fprintf(stderr, "Erro: lista cheia ou \"pos\" fora do escopo do tamanho da lista\n");
            break;
        }

        imprimir(lista);
        printf("\n");

        break;

    case 3:
        printf("Digite o nome do registro a ser removido: ");
        fgets(dado_dentro.nome, MAXNOME, stdin);
        
        if (!remover(lista, dado_dentro))
        {
            printf("Erro: Caractere nao esta na lista ou lista esta vazia.\n");
            break;
        }

        break;

    case 4:
        if (lista_existe(lista))
            printf("\nTamanho maximo da sua lista e= %d\n", tamanho(lista));
        else
            printf("Erro: Lista nao existe!\n");

        break;

    case 5:
        printf("Digite uma posicao:\n");
        scanf("%d", &pos); getchar();

        if (consultaPosicao(lista, pos, &dado_dentro))
            printa_dado(&dado_dentro, pos);
        else
            printf("Erro: nao e possivel acessar essa posicao.\n");
        break;

    case 6:
        printf("Digite um nome a ser buscado>> ");
        fgets(dado_dentro.nome, MAXNOME, stdin);

        if (consultaNome(lista, &dado_dentro, &pos))
        {
            printf("Registro \"%s\" encontrado na posicao %d.\n", dado_dentro.nome, pos);
            printa_dado(&dado_dentro, pos);
        }
        else
            printf("Registro nao encontrado.\n");

        break;

    case 7:
        if (esta_vazia(lista))
            printf("Erro: Listavazia\n");
        else
        {
            printf("A lista e:\n");
            imprimir(lista);
            printf("\n");
        }
        break;
    
    case 8:
        printf("Digite um nome a ser buscado>> ");
        fgets(dado_dentro.nome, MAXNOME, stdin);

        if (consultaNome(lista, &dado_dentro, &pos))
        {            
            atualiza(lista, &dado_dentro, pos);
            printf("Registro \"%s\" encontrado na posicao %d.\n", dado_dentro.nome, pos);
            printf("Registro Atualizado!\n");
            printa_dado(&dado_dentro, pos);
        }
        else
            printf("Registro nao encontrado.\n");
        break;

    case 9:
        destroi(lista);
        break;
    }
}
