/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Dynamic Queue functions.
    Date:        11/02/2021
************************************************************************************/

#include <stdlib.h>
#include "FilaDinamica.h"

void create_Queue(QUEUE* q)
{
    *q = NULL;
}

int is_Queue_Empty(QUEUE q)
{
    return q == NULL;
}

int first_number_Queue(QUEUE q, int* number)
{
    QUEUE first;

    if (is_Queue_Empty(q))
        return 0;
    else
    {
        first = q;

        while (first->next != NULL)
            first = first->next;
        
        *number = first->data;
    
        return 1;
    }
}

int insert_Queue(QUEUE* q, int data)
{
    NODE* aux;

    aux = (NODE*)malloc(sizeof(NODE));
    aux->data = data;
    aux->next = *q;
    *q = aux;
}

int remove_Queue(QUEUE* q, int* data)
{
    QUEUE first, second;

    if (is_Queue_Empty(*q))
        return 0;
    else
    {
        first = *q;
        second = NULL;

        while (first->next != NULL)
        {
            second = first;
            first = first->next;
        }

        *data = first->data;

        if (second == NULL)
            *q = NULL;
        else
            second->next = NULL;

        free(first);

        return 1;
    }
    
}