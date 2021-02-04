/***********************************************************************************
    Author:      Lucas Pachco.
    Description: Static Stack abstract type and prototypes.
    Date:        02/02/2021
************************************************************************************/

#define MAX 100
#define BASE -1

typedef struct tstack
{
    int stack[MAX];
    int top;
} STACK;

int isFull (STACK s);
int isEmpty(STACK s);

void create_Stack(STACK *s);
int  _insert_(STACK *s, int number);
int  _remove_(STACK *s, int *number);
int  top_number(STACK s);
