#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista TLista;

TLista *cria_lista();

int esta_vazia(TLista* lista);

int esta_cheia();

int inserir(TLista *lista, char x);

int remover(TLista *lista, char x);

int acessar(TLista *lista, int i, char *elem);

int devolver(TLista *lista, char x, int *pos);

int tamanho(TLista *lista);

void imprimir(TLista *lista);

void destroi(TLista *lista);

#endif // LISTA_H_INCLUDED
