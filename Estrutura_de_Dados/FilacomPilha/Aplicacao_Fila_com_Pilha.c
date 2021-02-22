/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Static Queue aplication example.
    Date:        19/02/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "filaComPilha.h"

QUEUESTACK queue;

void list_QUEUE(QUEUESTACK* q);

void clean_screen();

int menu()
{   
    int op;
    printf("--------------------------\n");
    printf("QUEUE MANIPULATION PROGRAM\n");
    printf("--------------------------\n");

    printf("Menu:\n");
    printf("1 - Create\n");
    printf("2 - Insert\n");
    printf("3 - Remove\n");
    printf("4 - Show First\n");
    printf("5 - List\n");
    printf("6 - Exit\n");
    printf("> ");
    
    scanf("%d", &op);
    getchar();
    
    clean_screen();

    return (op);
}

void option(int op)
{   
    int data;

    switch (op)
    {
        case 1: 
            QS_create(&queue);
            break;
            
        case 2: 
            if (QS_isFull(queue))
                printf("Error: Queue is full!\n");
            else
            {
                printf("\nType a number > ");
                scanf("%d", &data);
                getchar();

                QS_Insert(&queue, data);
            }
            break;

        case 3: 
            if (QS_isEmpty(queue))
                printf("Error: Queue is empty!\n");
            else
            {
                QS_Remove(&queue, &data);
                printf("Data removed: %d\n", data);
            }
            break;

        case 4: 
            if (QS_isEmpty(queue))
                printf("Error: Queue is empty!\n");
            else
            {
                QS_first(queue, &data);

                printf("First: %d\n\n", data);
            }
            break;

        case 5:
            if (QS_isEmpty(queue))
                printf("Error: Queue is empty!\n");
            else
                list_QUEUE(&queue);
            
            break;
    }
}

int main()
{   
    int op;

    do
        option(op = menu());
    while (op != 6);

    return 0;
}

void list_QUEUE(QUEUESTACK* q)
{
    int size = q->top + 1, data;
    QUEUESTACK aux;
    QS_create(&aux);

    for (int i = 0; i < size; i++)
    {    
        QS_Remove(q, &data);   
        QS_Insert(&aux, data);            
    }

    for (int i = 0; i < size; i++)
    {
        QS_Remove(&aux, &data);
        printf("%d ", data);
        QS_Insert(q, data);
    }     
    printf("press anything...");
    getchar();        
    clean_screen();
}

void clean_screen()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
}