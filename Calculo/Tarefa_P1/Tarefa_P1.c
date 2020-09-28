/*
    * Author:       Lucas Matheus Silva Pacheco.
    * Description:  Alguns exercícios de Cálculo(I) - James Stewart (2.6).   
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void   menu();
int    limite_inf(int op, int valor_i, int valor_f, int passo);
double questao(int op, int x);

/* MAIN */
int main()
{
    int qualQuest; /* Armazena a questão selecionada pelo usuário. */
    int valor_i, 
        valor_f;
    int passo;
    
    do
    {
        menu();

        fprintf(stdout, "Digite o a questao desejada ou 0 para sair do programa: ");
        fscanf (stdin,  "%d", &qualQuest);
        
        if (!qualQuest) 
            break;

        if ((qualQuest != 15) && (qualQuest != 16) && (qualQuest != 24) && (qualQuest != 31) && (qualQuest != 33) && (qualQuest != 34))
        {
            system("clear"); /* WINDOWS: system("cls"); */
            fprintf(stderr, "ATENCAO:Digite uma questao valida.\n\n");  
            qualQuest = 0;
            continue;
        }

        fprintf(stdout, "Digite o valor inicial para x: ");
        fscanf (stdin,  "%d", &valor_i);

        fprintf(stdout, "Digite o valor final para x: ");
        fscanf (stdin,  "%d", &valor_f);

        fprintf(stdout, "Digite o valor para o passo de x: ");
        fscanf (stdin,  "%d", &passo);

    } while (limite_inf(qualQuest, valor_i, valor_f, passo));
    
    return 0;
}

/*
    FUNCOES.
*/
void menu()
{
    /* Cabeçalho */
    fprintf(stdout, "Este programa explora limites com x->[+inf] ou com x->[-inf]:                     \n");
    
    /* Menu de exercícios */
    fprintf(stdout, "Exercicio 15: Limite[1/(2x + 3)] quando x->[+inf]                                 \n");
    fprintf(stdout, "Exercicio 16: Limite[(3x + 5)/(x - 4)] quando x->[+inf]                           \n");
    fprintf(stdout, "Exercicio 24: Limite[sqrt(9x^6 - x)/(x^3 + 1)] quando x->[-inf]                   \n");
    fprintf(stdout, "Exercicio 31: Limite[x^4 + x^5] quando x->[-inf]                                  \n");
    fprintf(stdout, "Exercicio 33: Limite[arctg(x)] quando x->[+inf]                                   \n");
    fprintf(stdout, "Exercicio 34: Limite[(exp(3x) - exp(-3x)) / (exp(3x) + exp(-3x))] quando x->[+inf]\n");
}

int limite_inf(int op, int valor_i, int valor_f, int passo)
{
    double lim;
    int i = valor_i,
        f = valor_f;
    
    if (!op)
        return 1;

    if (valor_f < 0)
    {
        for(;i >= f; i += passo)
            fprintf(stdout, "O valor da funcao em %5d e: %.16lf\n", i, (double)questao(op, i));
    }
    else if (valor_f > 0)
    {
        for(;i <= f; i += passo)
            fprintf(stdout, "O valor da funcao em %5d e: %.16lf\n", i, (double)questao(op, i));
    }
    
    fprintf(stdout, "\n\n");

    return 1;
}

double questao(int op, int x)
{
    double lim = 0.00001;

    switch (op)
    {
    case 15:
        lim = (1 / (2 * (double)x + 3));    
        break;

    case 16:
        lim = (3 * (double)x + 5) / ((double)x - 4);
        break;

    case 24:
        lim = (sqrt(9 * pow(x, 6) - (double)x)) / (pow(x, 3) + 1);
        break;

    case 31:
        lim = pow(x, 4) + pow(x,5);
        break;

    case 33:
        lim = atan(x);
        break;
    
    case 34:
        lim = (exp(3 * (double)x) - exp(-3 * (double)x)) / (exp(3 * (double)x) + exp(-3 * (double)x));
    default:
        break;
    }

    return lim;
}