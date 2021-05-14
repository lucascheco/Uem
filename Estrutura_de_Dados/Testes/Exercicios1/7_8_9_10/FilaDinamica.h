#define MAXNOME 80
#define MAXVET  100

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

typedef NO* FILA;

void criaFila(FILA* fila);

int filaVazia(FILA fila);

int tem_um(FILA fila);

int primeiroFila(FILA fila, DADO* dado);

int enfileira(FILA* fila, DADO dado);

int desenfileira(FILA* fila, DADO* dado);

int removeFila(FILA* fila, char nome[], DADO* dado);

int removeMenorfila(FILA* fila, DADO* dado);

void ordenafila(FILA* fila);