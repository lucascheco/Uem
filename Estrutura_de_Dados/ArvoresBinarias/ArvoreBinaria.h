/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Árvores Binárias, tipos abstratos.
    Date:        25/03/2021
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

typedef NO* NOARVORE;

typedef struct arvore
{
    NOARVORE raiz;
    int      quant;
} ARVORE;


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

int consultaAscendente(ARVORE A, DADO* dado, int nivel);

int mostra_ABB(ARVORE A);

typedef struct _pilha
{
    NOARVORE dado;
    struct _pilha* prox;
}
_pilha;

typedef _pilha* PILHA;

void criar_Pilha   (PILHA *pilha);

int pilha_EstaVazia(PILHA pilha);

int topo        (PILHA  pilha, NOARVORE *top);

int insere_Pilha(PILHA *pilha, NOARVORE dado);

int remove_Pilha(PILHA *pilha, NOARVORE *dado);
