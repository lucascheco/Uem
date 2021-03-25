#include <stdio.h>
#include <stdlib.h>
#include "ListaDinOrdDupEnc.h"

void clean_screen()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
}

tipoLista LISTA;

int menuOpcao()
{   int op;

    printf("\nMenu de Opcoes");
    printf("\n<1> criar lista");
    printf("\n<2> inserir na lista");
    printf("\n<3> remover da lista");
    printf("\n<4> consultar por nome");
    printf("\n<5> consultar por posicao");
    printf("\n<6> quantidade de elementos");
    printf("\n<7> mostrar a lista");
    printf("\n<8> AtualizarNome");
    printf("\n<9> sair");
    printf("\nEscolha a opcao > ");
    scanf("%d",&op); getchar();
    clean_screen();
    return (op);
}

void trataOpcao(int op)
{   tipoDado dado, novo;
    int posicao, quant;

    switch (op)
    {
        case 1: criaLista(&LISTA);
                break;
        case 2: if (listaCheia(LISTA))
                    printf("\nLista Cheia! Dado nao inserido!\n");
                else
                {
                    printf("\nDigite o dado a ser inserido > \n");
                    printf("\nNome: ");
                    fgets(dado.nome, 75, stdin);
                    printf("\nDia de Nascimento: ");
                    scanf("%d",&(dado.dnasc.dia)); getchar();
                    printf("\nMes de Nascimento: ");
                    scanf("%d",&(dado.dnasc.mes)); getchar();
                    printf("\nAno de Nascimento: ");
                    scanf("%d",&(dado.dnasc.ano)); getchar();
                    printf("\nRegistro Geral: ");
                    scanf("%d",&(dado.rg)); getchar();

                    insereLista(&LISTA, dado);

                    printf("\nRegistro Inserido\n");
                }
                break;
        case 3: if (listaVazia(LISTA))
                    printf("\nLista Vazia! Dado nao removido!\n");
                else
                {
                    printf("\nDigite o nome a ser removido > \n");
                    printf("\nNome: ");
                    fgets(dado.nome, 75, stdin);
                    if (removeLista(&LISTA,&dado))
                    {
                        printf("\nRegistro Removido: \n");
                        printf("\nNome: %s",dado.nome);
                        printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                        printf("\nMes de Nascimento: %d",dado.dnasc.mes);
                        printf("\nAno de Nascimento: %d",dado.dnasc.ano);
                        printf("\nRegistro Geral: %d\n",dado.rg);
                    }
                    else printf("\nRegistro Inexistente!");
                }
                break;
        case 4: if (listaVazia(LISTA))
                    printf("\nLista Vazia! Dado nao pode ser consultado!\n");
                else
                {
                    printf("\nDigite o nome a ser consultado > \n");
                    printf("\nNome: ");
                    fgets(dado.nome, 75, stdin);
                    if (consultaPorNome(LISTA,&dado))
                    {
                        printf("\nRegistro Consultado: \n");
                        printf("\nNome: %s",dado.nome);
                        printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                        printf("\nMes de Nascimento: %d",dado.dnasc.mes);
                        printf("\nAno de Nascimento: %d",dado.dnasc.ano);
                        printf("\nRegistro Geral: %d\n",dado.rg);
                    }
                    else printf("\nRegistro Inexistente!");
                }
                break;
        case 5: if (listaVazia(LISTA))
                    printf("\nLista Vazia! Dado nao pode ser consultado!\n");
                else
                {
                    printf("\nDigite a posicao (ordem) do registro a ser consultado > \n");
                    printf("\nPosicao: ");
                    scanf("%d", &posicao); getchar(); 
                    if (consultaPorPosicao(LISTA,posicao,&dado))
                    {
                        printf("\nRegistro Consultado: \n");
                        printf("\nPosicao: %d", posicao);
                        printf("\nNome: %s",dado.nome);
                        printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                        printf("\nMes de Nascimento: %d",dado.dnasc.mes);
                        printf("\nAno de Nascimento: %d",dado.dnasc.ano);
                        printf("\nRegistro Geral: %d\n",dado.rg);
                    }
                    else printf("\nPosicao de Registro Inexistente!");
                }
                break;
        case 6: printf("\nQuantidade de Elementos na Lista = %d\n",quantLista(LISTA));
                break;

        case 7: if (listaVazia(LISTA))
                    printf("\nLista Vazia!!!\n");
                else
                {
                    printf("\nElementos da Lista:\n");
                    quant = quantLista(LISTA);
                    for (posicao=1; posicao<=quant; posicao++)
                    {
                        consultaPorPosicao(LISTA,posicao,&dado);
                        printf("\nRegistro Nro %d:", posicao);
                        printf("\nNome: %s",dado.nome);
                        printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                        printf("\nMes de Nascimento: %d",dado.dnasc.mes);
                        printf("\nAno de Nascimento: %d",dado.dnasc.ano);
                        printf("\nRegistro Geral: %d\n",dado.rg);
                    }
                }
                break;

            case 8:
                
                printf("Digite um nome para atualizar:");
                fgets(dado.nome, 75, stdin);
                printf("Digite o novo nome:");
                fgets(novo.nome, 75, stdin);

                atualizaNomeLista(&LISTA, dado.nome, novo.nome);
                break;

    }
}

void main(void)
{   int opcao;

    printf("\nAplicacao de Manipulacao de Lista\n\n");

    do
    {
        opcao=menuOpcao();
        trataOpcao(opcao);
    } while (opcao!=9);
}




