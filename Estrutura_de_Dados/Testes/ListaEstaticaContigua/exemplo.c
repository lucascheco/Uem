#include <stdio.h>
#include <stdlib.h>


void muda_para10(int* num)
{
    *num = 10;
}

int main()
{
    int* x = malloc(sizeof(int));
    int y = 21;
    
    muda_para10(&y);
    
    muda_para10(x);

    printf("%d\n", y);

    printf("%d\n", *x);
}
