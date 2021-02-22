/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: QueueStack functions.
    Date:        21/02/2021
************************************************************************************/


#include <stdlib.h>
#include "filaComPilha.h"

void QS_create(QUEUESTACK* qs)
{
    create_Stack(qs);
}

int QS_isFull(QUEUESTACK qs)
{
    return isFull(qs);
}

int QS_isEmpty(QUEUESTACK qs)
{
    return isEmpty(qs);
}

int QS_first(QUEUESTACK qs, int* data)
{
    if (isEmpty(qs))
        return 0;
    else
    {
        STACK aux;
        create_Stack(&aux);
        
        while (!isEmpty(qs))
        {
            _remove_(&qs, data);
            _insert_(&aux, *data);
        }
        
        *data = top_number(aux);

        while (!isEmpty(qs))
        {
            _remove_(&aux, data);
            _insert_(&qs, *data);
        }

        return 1;
    }    

}

int QS_Insert(QUEUESTACK* qs, int data)
{
    if (isFull(*qs))
        return 0;
    else
    {
        _insert_(qs, data);
        return 1;
    }
}

int QS_Remove(QUEUESTACK* qs, int *data)
{
    if (isEmpty(*qs))
        return 0;
    else
    {
        int datain;
        STACK aux;
        create_Stack(&aux);
        
        while (!isEmpty(*qs))
        {
            _remove_(qs, &datain);
            _insert_(&aux, datain);
        }
        
        _remove_(&aux, &datain);

        *data = datain;

        while (!isEmpty(aux))
        {
            _remove_(&aux, &datain);
            _insert_(qs, datain);
        }

        return 1;
    }    
}
