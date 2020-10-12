#define Verdadeiro 1
#define Falso      0

typedef char** Argumentos;
typedef int    Contador;
typedef int    Flag;

enum {PROGRAMA, MODO, ARQUIVO};
enum {FLAGS, IMPORT, OPER};

int modo(Flag flag, FILE *arq_source, FILE *arq_destination);

int importaArq_LED(FILE *arq_source, FILE *arq_destination);

int importaArq_OPR(FILE *arq_source, FILE *arq_oper);


char *busca(FILE *arq_oper);

int remove_();

int insere();

