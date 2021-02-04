/***********************************************************************************
    Author:      Lucas Pachco.
    Description: Dynamic Stack functions.
    Date:        04/02/2021
************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h"

void create_Stack(STACK* s)
{
    *s = NULL;    
}

int isEmpty(STACK s)
{
    return s == NULL;
}

int top_number(STACK s, int* top)
{
    if (isEmpty(s))
        return 0;
    else
    {
        *top = s->data;
        return 1;
    }
}

int _insert_(STACK* s, int data)
{
    NODE* aux;

    aux = (NODE*)malloc(sizeof(NODE));
    aux->data = data;
    aux->next = *s;

    *s = aux;

    return 1;
}

int _remove_(STACK* s, int* data)
{
    NODE* aux;

    if (isEmpty(*s))
        return 0;
    else
    {
    
        *data = (*s)->data;
        aux = *s;
        *s = aux->next;

        free(aux);
        return 1;
    }
}
