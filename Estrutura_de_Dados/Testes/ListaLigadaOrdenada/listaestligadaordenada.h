#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista TLista;
void debug_lista(const TLista* lista);

int lista_existe(const TLista* lista);

int esta_vazia(const TLista* lista);

int esta_cheia(const TLista* lista);

TLista* cria_lista (int tam);

int inserir(TLista* lista, char x);

int remover(TLista* lista, char x);

int acessar(TLista* lista, int pos, char *x);

int devolver(TLista* lista, int *pos, char x);

int tamanho (const TLista* lista);

void imprimir(const TLista* lista);

void destroi(TLista* lista);

#endif // LISTA_H_INCLUDED
