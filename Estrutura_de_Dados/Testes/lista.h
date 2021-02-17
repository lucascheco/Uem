#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista TLista;

TLista* cria_lista (int tam); //Done

int lista_existe(TLista* lista); // Done

int lista_vazia(TLista* lista); //Done  

int lista_cheia(TLista* lista, int tam); //Done 

void destroi(TLista* lista); //Done

int tamanho (TLista* lista); //Done

int quantidade(TLista* lista); //Done

void imprimir(TLista* lista); //Done

int inserir(TLista* lista, char c, int pos); //Acho q ta feita

int remover(TLista* lista, int pos);

int acessar(TLista* lista, int pos, char* elem);

int devolver(TLista* lista, char c, int* pos);

#endif // LISTA_H_INCLUDED
