#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 64

int main()
{
    char input[BUFLEN] = "Rey, Luke, Leia: Anakin, Pad_me";
    int i = 0;

    char  *token = strtok(input, "-");
    
    printf("%d:[%p] --- %s\n", i, token, token);

    
    token = strtok(input, ",");
    
    printf("%d:[%p] --- %s\n", i, token, token);

    while (token != NULL)
    {
        token = strtok(NULL, ",:");

        printf("%d:[%p] --- %s\n", i, token, token); 
    }    

    printf("%s\n", input);
    return 0;
}