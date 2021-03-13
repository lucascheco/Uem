/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Lista dinâmica ordenada encadeada, tipos abstratos.
    Date:        11/03/2021
************************************************************************************/

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAXNOME 25

typedef struct tipoDN
{
    int dia, mes, ano;
} 
DN;

typedef struct dado
{
    char  nome[MAXNOME];
    DN    dnasc;
    int   rg;
    char  genero;
    char  profissao[MAXNOME];
    float salario;
}
DADO;

typedef struct Lista TLista;

TLista *cria_lista();

int lista_existe(const TLista* lista);

int esta_vazia(TLista* lista);

int esta_cheia();

int inserir(TLista* lista, DADO dado);

int remover(TLista* lista, DADO dado);

int consultaPosicao(TLista* lista, int i, DADO* dado);

int consultaNome(TLista* lista, DADO* dado, int* posicao);

int atualiza(TLista* lista, DADO* dado, int posicao);

int tamanho(TLista* lista);

void printa_dado(const DADO* dado, int i);

void imprimir(TLista* lista);

void destroi(TLista* lista);

#endif // LISTA_H_INCLUDED
