/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Registers.
    Date:        26/01/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char NAME[50];

typedef struct reg
{
    NAME name;
    int  age;
} REGISTRO;

typedef REGISTRO REGISTERS[50];

void clear_term()
{
#ifdef _WIN32
    system("cls");
#endif

#ifdef linux
    system("clear");
#endif
}
int  menu();
void insertRegister(REGISTRO*  reg);
void showRegisters (REGISTERS  registers, int  size);
int  searchName    (REGISTERS  registers ,int  size, NAME name);
void removeRegister(REGISTERS* registers, int  size, int achou);

void main(void)
{   
    REGISTERS registers;
    NAME      name;
    int       size = 0;
    int       op;
    int       achou = 0;

    do
    {
        printf("-----------------------\n");
        printf(" Registration Program:\n");
        printf("-----------------------\n");

        op = menu();

        switch (op)
        {
            case 1:
                if (size < 50) 
                {
                    insertRegister(&registers[size]);
                    size++;
                }
                else
                {
                    printf("Registros esta cheio.\n");
                }

                break;

            case 2:
                printf("Type a name to remove: ");
                fgets(name, sizeof(name), stdin);
                achou = searchName(registers, size, name);

                if (achou >= 0) 
                {
                    printf("Achou na posicao %d\n", achou);
                    removeRegister(&registers, size, achou);
                    size--;
                }
                else if (achou == -1)
                    printf("Registro nao cadastro.\n");

                break;

            case 3: 
                showRegisters(registers, size);

                break;
        }

    } while (op != 4);
}

int menu()
{   
    int op;

    printf("\nType:\n");
    printf("1 - Insert register\n");
    printf("2 - Remove register\n");
    printf("3 - Show   register\n");
    printf("4 - Exit\n");
    printf("->");
    scanf("%d", &op);
    getchar();
   
    clear_term(); 
    return (op);
}

void insertRegister(REGISTRO* reg)
{
    printf("Name : ");
    fgets(reg->name, sizeof(reg->name), stdin);
    
    printf("Age : ");
    scanf("%d", &(reg->age));

    clear_term();
}

void showRegisters(REGISTERS registers, int size)
{
    printf("\nRegisters:\n");
    printf("------------------------------\n");
        for (int i = 0; i < size; i++)
        {   
            printf("Register %d->\n", i + 1);
            printf("\t-Name: %s",   registers[i].name);
            printf("\t-Age : %d\n", registers[i].age);
        }
    printf("------------------------------\n");
    printf("\n\nPress Enter to exit ...");
    getchar();

    clear_term();
}

void removeRegister(REGISTERS* registers, int size, int achou)
{
    int i = achou;
    NAME copiar_nome;

    printf("Funcao remocao:\n");
    
    for (; i + 1 < size; i++)
    {
        strcpy(copiar_nome, (*registers)[i+1].name);
        strcpy((*registers)[i].name, copiar_nome);
    }

        printf("Registro removido...\n");
}


int searchName(REGISTERS registers, int size, NAME name)
{
    int i = 0;
    int flag = 0;

    while (i < size)
    {
        if (!strcmp(registers[i].name, name))
        {
            flag = 1;
            break;
        }
        i++;
    }
    
    if (flag)
        return i;
    else
        return -1;
}
