/*
    Autores: 
        *   Lucas Pacheco   - RA:112686.
        *   João Casagrande - RA:112684.
        *   Polyana Gaspar  - RA:107678.
    
    Descrição:
        * Árvore B.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MY_LIB1.h"

int main(Contador c, Argumentos p)
{
    if (c < 2)
    {
        fprintf(stderr, "Erro: numero incorreto de argumentos.\n");
        fprintf(stderr, "> Modo de uso:\n");
        fprintf(stderr, "$ %s -c arquivos_chaves.\n", p[PROGRAMA]);
        fprintf(stderr, "$ %s -p\n", p[PROGRAMA]);

        exit(1);
    }

    if (strcmp(p[MODO], "-c") == 0)
    {
        printf("Criando Arvore-B... ");
        criar(p[ARQ]);
        printf("Arvore-B criada com sucesso.\n");
    }
    else if (strcmp(p[MODO], "-p") == 0)
    {
        imprimir_relatorio();
    }
    else
    {
        fprintf(stderr, "Erro: opcao \"%s\" invalida.\n", p[MODO]);
    }
    
    return 0;
}