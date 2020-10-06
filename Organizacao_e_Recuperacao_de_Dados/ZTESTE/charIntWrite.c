#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    long int x = 10;
    char ch1 = '1', ch2 = '2';

    if((fp = fopen("teste1.txt", "wb")) == NULL)
    {
        fprintf(stderr, "Erro ao criar arquivo para escrita.\n");
        exit(1);
    }

    fwrite(&ch1, sizeof(char), 1, fp);
    fwrite(&ch2, sizeof(char), 1, fp);

    fclose(fp);
    return 0;
}