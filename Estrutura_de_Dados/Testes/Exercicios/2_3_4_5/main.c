#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDinamica.h"

PILHA pilha;

DADO dado1 = {
    "Amanda",
    21,
    31231
};

DADO dado2 = {
    "Talita",
    24,
    43234
};

DADO dado3 = {
    "Lucas",
    233,
    61626
};

DADO dado4 = {
    "Zebra",
    12,
    63433
};

void clean_screen()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
}

void mostraPilha(PILHA pilha)
{          
    while (pilha != NULL)
    {
        printf("\t|%s|\n", pilha->dado.nome);
        pilha = pilha->prox;
    }
    printf("\t^^^^\n\n");
   
}

int main()
{
    DADO aux;

    criaPilha(&pilha);
    
    empilha(&pilha, dado4);
    empilha(&pilha, dado1);
    empilha(&pilha, dado2);
    empilha(&pilha, dado3);

    
    mostraPilha(pilha);


    ordenaPilha(&pilha);
    printf("\n\n");
    mostraPilha(pilha);


    return 0;
}