/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Static Queue abstract types and prototypes.
    Date:        11/02/2021
************************************************************************************/

#define MAX 100

typedef struct Qqueue
{
    int queue[MAX];
    int first, last, total;
} QUEUE;

void create_Queue (QUEUE* q);

int is_Queue_Empty(QUEUE  q);
int is_Queue_Full (QUEUE  q);

int first_Queue   (QUEUE  q, int* data);

int insert_Queue  (QUEUE* q, int  data);
int remove_Queue  (QUEUE* q, int* data);