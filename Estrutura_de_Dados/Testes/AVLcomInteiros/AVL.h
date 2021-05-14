/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Árvores Binárias balanceadas, tipos abstratos.
    Date:        15/04/2021
************************************************************************************/

#define MAXNOME 80

typedef struct dado
{
    int numero;
} DADO;

typedef struct no
{
    DADO dado;
    struct no *esq, *dir;
    int balanco;
} NO;

typedef NO *ARVORE;

int cria_AVL(ARVORE *A);

int AVL_estaVazia (ARVORE A);
int quantidade_AVL(ARVORE A);

int insere_AVL(ARVORE *A, DADO  dado);
int remove_AVL(ARVORE *A, DADO *dado);

int consulta_AVL          (ARVORE A, DADO* dado);

int preOrdem(ARVORE A);
int emOrdem (ARVORE A);
int posOrdem(ARVORE A);


int mostra_AVL(ARVORE A);

typedef struct _pilha
{
    ARVORE dado;
    struct _pilha* prox;
}
_pilha;

typedef _pilha* PILHA;

void criar_Pilha   (PILHA *pilha);
int pilha_EstaVazia(PILHA pilha);

int topo        (PILHA  pilha, ARVORE *top);
int insere_Pilha(PILHA *pilha, ARVORE dado);
int remove_Pilha(PILHA *pilha, ARVORE *dado);