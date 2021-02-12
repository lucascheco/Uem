/***********************************************************************************
    Author:      Lucas Pacheco.
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

int is_Stack_Empty(STACK s)
{
    return s == NULL;
}

int top_number(STACK s, int* top)
{
    if (is_Stack_Empty(s))
        return 0;
    else
    {
        *top = s->data;
        return 1;
    }
}

int insert_Stack(STACK* s, int data)
{
    NODE* aux;

    aux = (NODE*)malloc(sizeof(NODE));
    aux->data = data;
    aux->next = *s;

    *s = aux;

    return 1;
}

int remove_Stack(STACK* s, int* data)
{
    NODE* aux;

    if (is_Stack_Empty(*s))
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
