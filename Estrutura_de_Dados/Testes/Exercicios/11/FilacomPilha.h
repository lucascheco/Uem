#include "../1/Pilha.h"

typedef PILHA FILA;

void criaFila(FILA* fila);

int filaCheia(FILA fila);

int filaVazia(FILA fila);

int primeiroFila(FILA fila, DADO* dado);

int enfileira(FILA* fila, DADO dado);

int desenfileira(FILA* fila, DADO* dado);