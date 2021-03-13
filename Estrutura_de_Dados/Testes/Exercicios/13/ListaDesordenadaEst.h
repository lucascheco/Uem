#define MAXNOME 80
#define MAXVET  100

typedef struct dado
{
    char nome[MAXNOME];
    int idade;
    int rg;
} DADO;

typedef struct elem
{
    DADO dado;
    int status;
}
ELEM;

typedef struct lista
{
    ELEM lista[MAXVET];
    int  quant;
} LISTA;

void criaLista(LISTA *lista);

int listaCheia(LISTA lista);

int listaVazia(LISTA lista);

int quantidade(LISTA lista);

int consultaNome(LISTA lista, DADO* dado);

int consultaPosicao(LISTA lista, int pos, DADO* dado);

int insereLista(LISTA* lista, DADO dado);

int removeLista(LISTA* lista, DADO* dado);

