#define MAXNOME 45

typedef struct tipoDN
{
    int dia, mes, ano;
} 
DN;

typedef struct dado
{
    char nome[MAXNOME];
    DN dnasc;
    int rg;
    char genero;
}
DADO;

typedef struct elem
{
    DADO dado;
    struct elem* prox;
}
ELEM;

typedef struct lista
{
    ELEM* lista;
    int quant;
}
LISTA;

void criaListaOrd(LISTA* L);

int esta_cheia(LISTA L);

int esta_vazia(LISTA L);

int quantidade(LISTA L);

int consulta_por_Nome(LISTA L, DADO* dado);

int consulta_por_Pos(LISTA L, int pos, DADO* dado);

int insere_Lista(LISTA* L, DADO dado);

int remove_Lista(LISTA* L, DADO* dado);

int atualizar(LISTA* L, DADO dado_atual);