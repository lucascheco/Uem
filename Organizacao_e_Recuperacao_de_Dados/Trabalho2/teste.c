#include <stdio.h>

typedef int bool;
bool true = 1, false = 0;

int  encript(int a, int b);
void dencript(int chave, int *a, int *b);

int main()
{
    int a, b;
    int chave;
    bool resp;


    printf("Digite dois numeros para gerar uma chave: ");
    scanf("%d %d", &a, &b);

    chave = encript(a, b);

    printf("Codigo %d encriptado!\n", chave);

    printf("Deseja Saber os numeros de volta?");

    return 0;
}

int encript(int a, int b)
{
    return a * b * b;
}

void dencript(int chave, int *a, int *b)
{

}