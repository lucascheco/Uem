#define Verdadeiro 1
#define Falso      0

typedef char** Palavras;
typedef int    Contador;
typedef int    Flag;

enum {PROGRAMA, MODO, ARQUIVO};
enum {FLAGS, IMPORT, OPER};

int modo(Flag flag);
