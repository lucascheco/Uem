#define NAMESIZE 30
#define CPFSIZE  11

typedef int numChar;

typedef struct 
{
    char  *nome;
    char  *cpf;
    double saldo;
}Registro;

typedef Registro *Conta;

void allocaConta(Conta *conta);

numChar getString(char *str, int size);

Conta digitarCampos();

void adicionarRegistroConta(Conta conta, FILE *arq);

void freeConta(Conta conta);
