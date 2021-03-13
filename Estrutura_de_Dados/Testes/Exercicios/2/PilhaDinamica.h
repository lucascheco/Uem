
#define MAXNOME 80

typedef struct dado
{
    char nome[MAXNOME];
    int idade;
    int rg;
} DADO;

typedef struct no
{
    DADO dado;
    struct no* prox;
} NO;

typedef NO* PILHA;

void criaPilha(PILHA* pilha);

int pilhaVazia(PILHA pilha);

int pilhaCheia(PILHA pilha);

int topoPilha(PILHA pilha, DADO* topo);

int empilha(PILHA* pilha, DADO dado);

int desempilha(PILHA* pilha, DADO* dado);