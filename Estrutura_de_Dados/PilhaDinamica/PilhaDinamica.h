/***********************************************************************************
    Author:      Lucas Pachco.
    Description: Dynamic Stack abstract type and prototypes.
    Date:        04/02/2021
************************************************************************************/

typedef struct node
{
    int data;
    struct node* next;
}
NODE;

typedef NODE* STACK;

void create_Stack(STACK *s);

int isEmpty(STACK s);

int top_number(STACK s, int *top);

int _insert_(STACK *s, int data);

int _remove_(STACK *s, int *data);

