/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Árvores Binárias Recursivas, tipos abstratos.
    Date:        15/04/2021
************************************************************************************/
#define MAXNOME 80

typedef struct dado 
{
    char nome[MAXNOME];
    int  idade;
    int  RG;
} DADO;

typedef struct no
{
    DADO dado;
    struct no* esq;
    struct no* dir;
} NO;

typedef NO* ARVORE;

int cria_ABB      (ARVORE *A);

int ABB_estaVazia (ARVORE A);

int ABB_estaCheia (ARVORE A);

int quantidade_ABB(ARVORE A);

int insere_ABB  (ARVORE* A, DADO dado);

int remove_ABB  (ARVORE* A, DADO* dado);

int consulta_ABB(ARVORE A, DADO* dado);

int preOrdem(ARVORE A);

int emOrdem (ARVORE A);

int posOrdem(ARVORE A);

int consultaPai(ARVORE A, DADO* dado);

int consultaAscendente(ARVORE A, DADO* dado);

int mostra_ABB(ARVORE A);