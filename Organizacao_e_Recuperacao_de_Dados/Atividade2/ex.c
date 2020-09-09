#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main()
// {   
//     char str[20];

//     fgets(str, 20, stdin);

//     fprintf(stdout, "O tamanho da string :%d \n", strlen(str));
//     fprintf(stdout, "As letras sao :\n");

//     for (int i = 0; i < strlen(str); i++)
//             fprintf(stdout, "%d Letra: %c \n", i + 1, str[i]);


//     return 0;
// }

int main()
{   
    char str[20];

    fscanf(stdin, "%[^\n]s", str);

    fprintf(stdout, "O tamanho da string :%d \n", strlen(str));
    fprintf(stdout, "As letras sao :\n");

    for (int i = 0; i < strlen(str); i++)
            fprintf(stdout, "%d Letra: %c \n", i + 1, str[i]);


    return 0;
}
/* 
    A diferença entre fscanf e fgets, é que o fgets coloca o \0 no final.
*/