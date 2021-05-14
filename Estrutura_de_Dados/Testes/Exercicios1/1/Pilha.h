
#define BASE    -1
#define MAXNOME 80
#define MAXVET  100

typedef struct dado
{
    char nome[MAXNOME];
    int idade;
    int rg;
} DADO;

typedef struct pilha
{
    DADO pilha[MAXVET];
    int topo;
} PILHA;

void criaPilha(PILHA* pilha);

int pilhaVazia(PILHA pilha);

int pilhaCheia(PILHA pilha);

int topoPilha(PILHA pilha);

int empilha(PILHA* pilha, DADO dado);

int desempilha(PILHA* pilha, DADO* dado);

int removeMenorPilha(PILHA* pilha, DADO* dado);