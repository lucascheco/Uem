/***********************************************************************************
    Author:      Lucas Pacheco.
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

int is_Stack_Empty(STACK s);

int top_number(STACK s, int *top);

int insert_Stack(STACK *s, int data);

int remove_Stack(STACK *s, int *data);

