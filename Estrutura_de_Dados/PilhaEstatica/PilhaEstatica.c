/***********************************************************************************
    Author:      Lucas Pachco.
    Description: Stack function.
    Date:        02/02/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.h"

int isFull(STACK s)
{
    return (s.top == MAX - 1);
}

int isEmpty(STACK s)
{
    return (s.top == BASE);
}

void create_Stack(STACK *s)
{
    s->top = BASE;
}

int _insert_(STACK *s, int number)
{
    if (isFull(*s))
        return 0;
    else
    {
        s->top++;
        s->stack[s->top] = number;
        return 1;
    }
}

int _remove_(STACK *s, int *number)
{
    if (isEmpty(*s))
        return 0;
    else
    {
        *number = s->stack[s->top];
        s->top--;
        return 0;
    }
}

int top_number(STACK s)
{

    return(s.stack[s.top]);
}
