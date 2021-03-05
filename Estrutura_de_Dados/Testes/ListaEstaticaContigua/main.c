#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "lista.h"

TLista* lista = NULL;

void app(int op);
int menu();   
void imprimir(TLista* lista1);
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
            printf("Digite a posicao: ");
            scanf("%d", &pos);  getchar();

            if (!inserir(lista, c, pos))
            {
                fprintf(stderr, "Erro: lista cheia ou \"pos\" fora do escopo do tamanho da lista\n");
                break;
            }
            printf("A lista de %d elementos e:\n", quantidade(lista));
            imprimir(lista);
            printf("\n");
            
            break;

        case 3:
            printf("Digite a posicao: ");
            scanf("%d", &pos);
            if (!remover(lista, pos))
            {
                printf("Erro: Posicao nao esta ocupada ou lista vazia.\n"); 
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
            scanf("%d", &pos);

            if (pos < tamanho(lista))
            {
                if(!acessar(lista, pos, &c))
                    printf("Erro: lista vazia.\n");
                
                printf("\n O elemento e >> %c.\n", c);
            }
            else
                printf("Erro: pos fora de escopo.\n");
            
            break;

        case 6:
            printf("Digite um caractere a ser buscado>> ");
            scanf("%c", &c); getchar();

            if (!lista_vazia(lista))
            {
                if (devolver(lista, c, &pos))
                    printf("Caracte \"%c\" encontrado na posicao %d.\n", c, pos);
                else
                    printf("Caractere nao encontrado.\n");        
            }
            else
                printf("Erro: A lista esta vazia.\n");
            break;

        case 7:
            printf("A lista e:\n");
            imprimir(lista);
            printf("\n");
            break;
        case 8:
            break;
    }

}
