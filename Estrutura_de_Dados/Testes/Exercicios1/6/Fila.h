
#define BASE    -1
#define MAXNOME 80
#define MAXVET  100

typedef struct dado
{
    char nome[MAXNOME];
    int idade;
    int rg;
} DADO;

typedef struct fila
{
    DADO fila[MAXVET];
    int  ultimo, total;
} FILA;

void criaFila(FILA* fila);

int filaVazia(FILA fila);

int filaCheia(FILA fila);

int primeiroFila(FILA fila, DADO* dado);

int enfileira(FILA* fila, DADO dado);

int desenfileira(FILA* fila, DADO* dado);