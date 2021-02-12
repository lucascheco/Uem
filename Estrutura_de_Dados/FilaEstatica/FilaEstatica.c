/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Static Queue functions.
    Date:        11/02/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

void create_Queue(QUEUE* q)
{
    q->total = 0;
    q->last = -1;
    q->first = 0;
}

int is_Queue_Empty(QUEUE  q)
{
    return q.total == 0;
}

int is_Queue_Full(QUEUE  q)
{
    return q.total == MAX;
}

int first_Queue(QUEUE  q, int* data)
{
    if (is_Queue_Empty(q))
        return 0;
    else
    {
        *data = q.queue[q.first];
        return 1;    
    }
}

int insert_Queue(QUEUE* q, int  data)
{
    if (is_Queue_Full(*q))
        return 0;
    else
    {
        if (q->last == MAX - 1)
            q->last = 0;
        else
            q->last++;

        q->queue[q->last] = data;
        q->total++;

        return 1;
    }
    
}

int remove_Queue(QUEUE* q, int* data)
{
    if (is_Queue_Empty(*q))
        return 0;
    else
    {
        *data = q->queue[q->first];

        if (q->first == MAX)
            q->first = 0;
        else
            q->first++;

        q->total--;

        return 1;
    }
}