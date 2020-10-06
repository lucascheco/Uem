#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    long int x;
    char ch;

    if((fp = fopen("teste1.txt", "rb")) == NULL)
    {
        fprintf(stderr, "Erro ao ler arquivo para escrita.\n");
        exit(1);
    }

    fread(&x, sizeof(long), 1, fp);

    fprintf(stdout, "O numero lido e %ld e o tamanho dele e de %ld bytes\n", x, sizeof(x));

    fclose(fp);
    return 0;
}