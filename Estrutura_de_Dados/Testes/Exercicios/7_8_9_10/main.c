#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaDinamica.h"

FILA fila;

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

void mostraFila(FILA fila)
{          
    while (fila != NULL)
    {
        printf("\t|%s|\n", fila->dado.nome);
        fila = fila->prox;
    }
    printf("\t^^^^\n\n");
   
}

int main()
{
    DADO aux;
    char nome[] = "Lucas\0";

    criaFila(&fila);
    
    enfileira(&fila, dado4);
    enfileira(&fila, dado1);
    enfileira(&fila, dado2);
    enfileira(&fila, dado3);

    
    mostraFila(fila);

    removeMenorfila(&fila, &aux);
    mostraFila(fila);
    removeMenorfila(&fila, &aux);
    mostraFila(fila);
    removeMenorfila(&fila, &aux);
    mostraFila(fila);
    // ordenafila(&fila);
    removeMenorfila(&fila, &aux);
    mostraFila(fila);
    // printf("\n\n");
    // mostraFila(fila);


    return 0;
}