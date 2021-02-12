/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Dynamic queue aplication.
    Date:        11/02/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "FilaDinamica.h"

QUEUE queue;

void list_QUEUE(QUEUE* q);

void clean_screen();

int menu()
{   
    int op;

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
            create_Queue(&queue);
            break;
            
        case 2: 
            printf("\nType a data > ");
            scanf("%d", &data);
            getchar();

            insert_Queue(&queue, data);
        
            break;

        case 3: 
            if (is_Queue_Empty(queue))
                printf("Error: Queue is empty!\n");
            else
            {
                remove_Queue(&queue, &data);
                printf("Data removed: %d\n", data);
            }
            break;

        case 4: 
            if (is_Queue_Empty(queue))
                printf("Error: Queue is empty!\n");
            else
            {
                first_number_Queue(queue, &data);

                printf("First: %d\n\n", data);
            }
            break;

        case 5:
            if (is_Queue_Empty(queue))
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
    {
        printf("--------------------------\n");
        printf("QUEUE MANIPULATION PROGRAM\n");
        printf("--------------------------\n");
        op = menu();
        option(op);

    } while (op != 6);

    return 0;
}

void list_QUEUE(QUEUE* q)
{
    QUEUE aux;
    int data;
    create_Queue(&aux);  

    while (*q != NULL)
    {
        remove_Queue(q, &data);     
        insert_Queue(&aux, data);      
    }

    while (aux != NULL)
    {
        remove_Queue(&aux, &data);
        printf("%d ", data);
        insert_Queue(q, data);
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