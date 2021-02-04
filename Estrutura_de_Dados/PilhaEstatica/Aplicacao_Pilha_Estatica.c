/***********************************************************************************
    Author:      Lucas Pachco.
    Description: Static Stack aplication example.
    Date:        02/02/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.h"

STACK stack;
int number;

int menu();
void option(int op);
void show_Stack(STACK s);
void list_Stack(STACK* s);

void clean_screen()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
}

int main()
{
    int op;

    printf("--------------------------\n");
    printf("STACK MANIPULATION PROGRAM\n");
    printf("--------------------------\n");
    
    do
    {
        op = menu();
        option(op);
    } while(op != 7);

    return 0;
}

int menu()
{
    int op;

    printf("Select a option:\n");
    printf("1 - CREATE STACK: \n");
    printf("2 - INSERT STACK: \n");
    printf("3 - REMOVE STACK: \n");
    printf("4 - SHOW TOP  STACK: \n");
    printf("5 - SHOW STACK: \n");
    printf("6 - LIST STACK: \n");
    printf("7 - EXIT\n");
    printf(">>>>");
    
    scanf("%d", &op);
    clean_screen();
    return op;
}

void option(int op)
{
    switch (op)
    {
        case 1:
            create_Stack(&stack);
            break;
        
        case 2:
            if (isFull(stack))
                printf("Error: Stack is full!\n");
            else
            {
                printf("Type a number:");
                scanf("%d", &number);
                _insert_(&stack, number);
                printf("\nInserted ...\n");
            }
            break;
        
        case 3:
            if (isEmpty(stack))
                printf("Error: Stack is empty!\n");
            else
            {
                _remove_(&stack, &number);
                printf("Top was Removed\n");
            }
            break;
    
        case 4:
            if (isEmpty(stack))
                printf("Error: Stack is empty!\n");
            else
                printf("Top: %d\n", top_number(stack));

            break;
        
        case 5:
            if (isEmpty(stack))
                printf("Error: Stack is empty\n");
            else
                show_Stack(stack);
           
            break;

        case 6:
            if (isEmpty(stack))
                printf("Error: Stack is empty!\n");
            else
                list_Stack(&stack); 
                
            break;

        case 7:
            break;
    }    
}

void show_Stack(STACK s)
{          
    clean_screen();
    for (int i = s.top; i > -1; i--)
        printf("\t|%d|\n", s.stack[i]);
    
    printf("\t^^^^\n\n");
    printf("press anything...");
    getchar();        
    getchar();
    clean_screen();
 }

void list_Stack(STACK* s)
{
    int size = s->top + 1;
    STACK aux;
    create_Stack(&aux);           
    for (int i = 0; i < size; i++)
    {    
        _remove_(s, &number);     
        _insert_(&aux, number);            
    }

    for (int i = 0; i < size; i++)
    {
        _remove_(&aux, &number);
        printf("%d ", number);
        _insert_(s, number);
    }     
    printf("press anything...");
    getchar();        
    getchar();
    clean_screen();
}
