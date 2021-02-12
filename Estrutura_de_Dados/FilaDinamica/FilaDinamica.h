/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Dynamic Queue abstract types and prototypes.
    Date:        11/02/2021
************************************************************************************/

typedef struct node
{
    int data;
    struct node* next;
}
NODE;

typedef NODE* QUEUE;

void create_Queue(QUEUE* q);

int is_Queue_Empty(QUEUE q);

int first_number_Queue(QUEUE q, int* number);

int insert_Queue(QUEUE* q, int data);

int remove_Queue(QUEUE* q, int* data);