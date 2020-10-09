#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char c;
    char *str;
    int x, cont = 0;

    str = (char *)malloc(sizeof(char));
    fp = fopen("livros.txt", "rw");
    
    c = fgetc(fp);
    str[cont] = c;

    while ((c = fgetc(fp)) != '|')
    {
        cont++;
        str = (char *)realloc(str, sizeof(int));
        str[cont] = c;
    }

    x = atoi(str);
    fprintf(stdout, "O tamanho desse registro e %d.\n", x);

    fclose(fp);
    return 0;
}