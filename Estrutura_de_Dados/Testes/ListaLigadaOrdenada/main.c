#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "listaestligadaordenada.h"

TLista* lista = NULL;

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
    while (op != 8);

    return 0;
}

int menu()
{
    int op;
    printf("------------------------------------\n");
    printf("            PROGRAM LISTA\n");
    printf("------------------------------------\n\n");

    printf("Selecione uma opcao:\n");
    printf("1-Criar Lista\n");
    printf("2-Inserir\n"); 
    printf("3-Remover\n");
    printf("4-Tamanho\n");
    printf("5-Acesso\n");
    printf("6-Devole\n");
    printf("7-Imprimir\n");
    printf("8-Exit\n");
    printf(">>>");
    
    scanf("%d", &op);
    getchar();
    clean_screen();
    
    return op;
}

void app(int op)
{
    int pos, tam;
    char c;

    switch(op)
    {
        case 1:
            printf("Digite um tamanho para lista >>");
            scanf("%d", &tam); getchar();
            
            if (tam > 2)
                lista = cria_lista(tam);
            else
                printf("Tamanho invalido.\n");
            break;
 
        case 2:
            if (!lista_existe(lista))
            {
                printf("Lista nao existe!\n");
                break;
            }
            printf("Digite o caractere: ");
            scanf("%c", &c);    getchar();

            if (!inserir(lista, c))
            {
                fprintf(stderr, "Erro: lista cheia ou \"pos\" fora do escopo do tamanho da lista\n");
                break;
            }

            debug_lista(lista);

            imprimir(lista);
            printf("\n");
            
            break;

        case 3:
            printf("Digite o caractere a ser removido: ");
            scanf("%c", &c);
            if (!remover(lista, c))
            {
                printf("Erro: Caractere nao esta na lista ou lista esta vazia.\n"); 
                break;
            }

            debug_lista(lista);
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

            if(!acessar(lista, pos, &c))
                printf("Erro: nao e possivel acessar essa posicao.\n");
            else
                printf("\n O elemento e >> %c.\n", c);
           
            break;

        case 6:
            printf("Digite um caractere a ser buscado>> ");
            scanf("%c", &c); getchar();

            if (devolver(lista, &pos, c))
                printf("Caracte \"%c\" encontrado na posicao %d.\n", c, pos);
            else
                printf("Caractere nao encontrado.\n");        

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
            destroi(lista);
            break;

    }
}
