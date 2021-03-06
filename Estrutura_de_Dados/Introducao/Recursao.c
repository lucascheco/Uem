/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Rercursão Fibonacci.
    Date:        29/01/2021
************************************************************************************/

#include <stdio.h>

long int fibonacci(long int n)
{
    if (n < 2)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2); 
}

int main()
{
    long int choice;

    printf("Type a number:");
    scanf("%ld", &choice);

    printf("\n\tThe %ld number of fibonacci sequence is %ld\n", choice, fibonacci(choice));

    return 0;
}
/*
OUTPUTSAMPLE:
    Type a number:(input)->46
            The 46 number of fibonnaci sequence is 1836311903

*/
