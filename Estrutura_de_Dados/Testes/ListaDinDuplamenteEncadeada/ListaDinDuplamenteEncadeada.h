#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista TLista; 

TLista* cria_lista (int tam);

int inserir(TLista* lista, int x);

int remover(TLista* lista, int x);

int acessar(TLista* lista, int i, int* elem);

int devolver(TLista* lista, int x, int *pos);

int tamanho (TLista* lista);

void imprimir(TLista* lista);

void destroi(TLista* lista);

#endif // LISTA_H_INCLUDED
