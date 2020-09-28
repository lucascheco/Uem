#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int n, char *params[])
{

    char *modo        = params[1];
    char *arq_entrada = params[2];
    char *arq_saida   = params[3];
    FILE *entrada;
    FILE *saida;
    char ch;

    if (n < 4) 
    {
        printf("Erro: falta de parametros [modo] [arq entrada] [arq saida]\n");
        exit(1);
    }
    
    if (n > 4) 
    {
        printf("Erro: muitos parametros [modo] [arq entrada] [arq saida]\n");
        exit(1);
    }

    if (strcmp(modo, "wl") && strcmp(modo, "lw")) 
    {
        printf("Erro: modo deve ser wl ou lw\n");
        exit(1);
    }

    if ((entrada = fopen(arq_entrada, "rb")) == NULL )
    {
        printf("Erro: O arquivo de entrada nao existe\n");
        exit(1);
    }

    saida = fopen(arq_saida, "wb");

    //windows para linux
    if (!strcmp(modo, "wl"))
    {
        while ((ch = fgetc(entrada)) != EOF)
        {
            if (ch != 13) {
                fputc(ch, saida);
            }
        }
        
    }
    //Linux para windows
    else if (!strcmp(modo, "lw"))
    {
        while ((ch = fgetc(entrada)) != EOF)
        {
            if (ch == 10) 
            {
                fputc(13, saida);
                fputc(10, saida);
            }
            else 
            {
                fputc(ch, saida);
            }
        }
    }

    fclose(entrada);
    fclose(saida);
    printf("Arquivo %s convertido para %s com modo %s\n", arq_entrada, arq_saida, modo);
    
    return 0;
}