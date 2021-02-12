/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Round brackets checking.
    Date:        09/02/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDinamica.h"

STACK stack;
char expression[100];

int main()
{
    int i, tam, error, data;
    int nOpened, nClosed;

    i = error = nOpened = nClosed = 0;

    printf("Math Round brackets checking.\n");
    printf("Type a math expression->>>");
    fgets(expression, 100, stdin);

    tam = strlen(expression);
    create_Stack(&stack);

    while ((i < tam) && (!error))
    {
        if (expression[i] == '(')
        {
            nOpened++;
            _insert_(&stack, nOpened);
        }
        else
        {
            if (expression[i] == ')')
            {
                nClosed++;
                if (!_remove_(&stack, &data))
                {
                    printf("Error: Missing open round bracktes %d.\n", nClosed);
                    error = 1;
                }
            }
        }

        i++;
    }

    if (isEmpty(stack))
        printf("Correct expression.\n");
    else
    {
        _remove_(&stack, &data);
        printf("Error: Missing close round brackets %d.\n", data);
    }
    
    return 0;
}