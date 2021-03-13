
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

int tem_um(PILHA pilha);

int pilhaCheia();

int topoPilha(PILHA pilha, DADO* topo);

int empilha(PILHA* pilha, DADO dado);

int desempilha(PILHA* pilha, DADO* dado);

int removePilha(PILHA* pilha, char nome[], DADO* dado);

int removeMenorPilha(PILHA* pilha, DADO* dado);

void ordenaPilha(PILHA* pilha);