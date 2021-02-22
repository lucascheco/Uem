#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista TLista;

TLista* cria_lista (int tam); 

int lista_existe(TLista* lista); 

int lista_vazia(TLista* lista);   

int lista_cheia(TLista* lista, int tam);  

void destroi(TLista* lista); 

int tamanho (TLista* lista); 

int quantidade(TLista* lista); 

void imprimir(TLista* lista); 

int inserir(TLista* lista, char c, int pos);

int remover(TLista* lista, int pos);

int acessar(TLista* lista, int pos, char* elem);

int devolver(TLista* lista, char c, int* pos);

#endif // LISTA_H_INCLUDED
