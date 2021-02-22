/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: QueueStack abstract types.
    Date:        21/02/2021
************************************************************************************/

#include "../PilhaEstatica/PilhaEstatica.h"

typedef STACK QUEUESTACK;

void QS_create(QUEUESTACK* qs);

int QS_isFull(QUEUESTACK qs);

int QS_isEmpty(QUEUESTACK qs);

int QS_first(QUEUESTACK qs, int* data);

int QS_Insert(QUEUESTACK* qs, int data);

int QS_Remove(QUEUESTACK* qs, int *data);
