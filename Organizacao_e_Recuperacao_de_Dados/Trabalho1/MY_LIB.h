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


char *le_Chave(FILE *arq_oper);

int busca(FILE *arq_source, int chaveBuscaInt);

int remove_(FILE *arq_source, int chaveBuscaInt);

int insere(FILE *arq_source, char *chaveBuscaChar);

void mostra_Reg(FILE *arq_source, int tam_Reg);

int leLED(FILE *arq_source);
