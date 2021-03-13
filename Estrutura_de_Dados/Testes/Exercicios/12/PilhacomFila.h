#include "../6/Filacircular.h"

typedef FILA PILHA;

void criaPilha(PILHA* pilha);

int pilhaVazia(PILHA pilha);

int pilhaCheia(PILHA pilha);

int topoPilha(PILHA pilha);

int empilha(PILHA* pilha, DADO dado);

int desempilha(PILHA* pilha, DADO* dado);