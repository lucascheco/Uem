#define ORDEM 5 /* Ordem da árvore, quantidade de ponteiros. */
#define BUFF  500

typedef char** Argumentos;
typedef int    Contador;

enum{PROGRAMA, MODO, ARQ};

/* A seguir, algumas flags para usarmos em funções. */
#define ENCONTRADO     1
#define NAO_ENCONTRADO 0
#define PROMOCAO       1
#define SEM_PROMOCAO   0
#define ERRO           3
#define INSERCAO       2

typedef struct cabecalho CABECALHO;

typedef struct paG PAGINA;

typedef struct pagAux PAGINA_AUX;


int ler_chave(FILE *arq, int *chave);

int RRN_novapag(FILE *arq_Avr_B);

void le_pagina(int RRN, PAGINA *pag, FILE *arq_Avr_B);

void escreve_pagina(int RRN, PAGINA *pag, FILE *arq_Avr_B);

int pos_chave(int chave, int chaves[], int num_chaves);

void inserir_chave_promocao(int chave_Promovida, int RRN_Promovido, int chaves[], int filhos[], int *num_chaves);

void inicializa_pagina(PAGINA *pag);

int busca_na_pagina(int chave, PAGINA pag, int *pos);

void insere_na_pagina(int chave, int filho_Direito, PAGINA *pag);

void insere_na_pagina_aux(int chave, int filho_Direito, PAGINA_AUX *pagaux);

void divide(int chave, int RRN, PAGINA *pag, int *chave_Promovida, int *filho_Direito_Promovido, PAGINA *novapag, FILE *arq_Avr_B);

int busca(int RRN, int chave, int *rrn_Encontrado, int *pos_Encontrada, FILE *arq_Avr_B);

int insere(int RRN_Atual, int chave, int *filho_Direito_Promovido, int *chave_Promovida, FILE *arq_Avr_B); 

void gerenciador(int RRN_Atual, int chave, int *filho_Direito_Promovido, int *chave_Promovida, FILE *arq_Avr_B);

void criar(char *nome_arq);

int insere_chave(int chave, int *RRN_Raiz, FILE *arq_Arv_B);

void imprime(FILE *arq_Avr_B);

int calcular_altura(FILE *arq_Arv_B);

void estatisticas(FILE *arq_Avr_B);

void imprimir_relatorio();