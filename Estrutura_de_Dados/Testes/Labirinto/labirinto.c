#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

#define maxLab 20

typedef int tipoLabirinto[maxLab][maxLab];

tipoLabirinto Lab =
{
    /*      00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19        */
    /* 00 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, /* 00 */
    /* 01 */ 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, /* 01 */
    /* 02 */ 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, /* 02 */
    /* 03 */ 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, /* 03 */
    /* 04 */ 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, /* 04 */
    /* 05 */ 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, /* 05 */
    /* 06 */ 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, /* 06 */
    /* 07 */ 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, /* 07 */
    /* 08 */ 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, /* 08 */
    /* 09 */ 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, /* 09 */
    /* 10 */ 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, /* 10 */
    /* 11 */ 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, /* 11 */
    /* 12 */ 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, /* 12 */
    /* 13 */ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, /* 13 */
    /* 14 */ 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, /* 14 */
    /* 15 */ 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, /* 15 */
    /* 16 */ 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, /* 16 */
    /* 17 */ 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, /* 17 */
    /* 18 */ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, /* 18 */
    /* 19 */ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, /* 19 */
    /*      00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19        */
};

int lin, col, cheguei, semSaida, linChegada, colChegada, linEntrada, colEntrada, retrocesso;

tipoPilha Pilha;
tipoDado dado, topo;

void identificaVizinhos(void)
{
    if (col>0) /* tem casa a esquerda */
    {   if ((Lab[lin][col-1]==1)&&(dado.sent_in!=direito))
            dado.esq=1;
        else dado.esq=0;
    }
    else dado.esq=0;

    if (col<maxLab-1) /* tem casa a direita */
    {   if ((Lab[lin][col+1]==1)&&(dado.sent_in!=esquerdo))
            dado.dir=1;
        else dado.dir=0;
    }
    else dado.dir=0;

    if (lin<maxLab-1) /* tem casa a frente */
    {   if ((Lab[lin+1][col]==1))
            dado.fro=1;
        else dado.fro=0;
    }
    else dado.fro=0;
}

void avancaCoordenada(int *semSaida)
{
    *semSaida=0;
    if (dado.esq==1)
        {
            col--;
            dado.esq=0;
            dado.sent_out=esquerdo;
            emPilha(&Pilha, dado);
            dado.sent_in=esquerdo;
            dado.col--;

            if ((lin==linChegada)&&(col==colChegada))
                cheguei = 1;
        }
        else if (dado.dir==1)
             {
                col++;
                dado.dir=0;
                dado.sent_out=direito;
                emPilha(&Pilha, dado);
                dado.sent_in=direito;
                dado.col++;

                if ((lin==linChegada)&&(col==colChegada))
                    cheguei = 1;
             }
             else if (dado.fro==1)
                  { lin++;
                    dado.fro==0;
                    dado.sent_out=frontal;
                    emPilha(&Pilha, dado);
                    dado.sent_in=frontal;
                    dado.lin++;

                    if ((lin==linChegada)&&(col==colChegada))
                        cheguei = 1;
                  }
                  else *semSaida=1;
}

void imprimeLabirinto(tipoLabirinto l)
{   int lin, col;

    for (lin=0; lin<maxLab;lin++)
    {
        for (col=0; col<maxLab; col++)
        {
            if (l[lin][col]==1)
                printf("%c%c", 35, 35);
            else printf("%c%c", 42, 42);
        }
        printf("\n");
    }
}


void imprimeCaminho(void)
{   tipoLabirinto auxLab;
    tipoDado auxD;
    int lin, col;


    for (lin=0; lin<maxLab;lin++)
        for (col=0; col<maxLab; col++)
            auxLab[lin][col]=0;

    auxLab[linChegada][colChegada]=1;

    while (!pilhaVazia(Pilha))
    {
        desemPilha(&Pilha, &auxD);
        auxLab[auxD.lin][auxD.col]=1;
    }
    imprimeLabirinto(auxLab);
}

void main(void)
{
    linChegada=maxLab-1;
    colChegada=4;
    linEntrada=0;
    colEntrada=2;

    cheguei = 0;
    retrocesso = 0;
    lin = linEntrada;
    col = colEntrada;
    dado.lin=lin;
    dado.col=col;
    dado.sent_in=0; /*nenhum*/
    semSaida=0;

    imprimeLabirinto(Lab);

    criaPilha(&Pilha);

    identificaVizinhos();

    if ((dado.esq+dado.dir+dado.fro)>1)
        dado.tronco=1;
    else dado.tronco=0;

    avancaCoordenada(&semSaida);

    while ((!semSaida)&&(!cheguei))
    {
        if (!retrocesso)
            identificaVizinhos();
        else retrocesso = 0;

        if (dado.esq+dado.dir+dado.fro>1)
            dado.tronco=1;
        else dado.tronco=0;

        avancaCoordenada(&semSaida);

        if (semSaida)
        {  /* nenhum vizinho a seguir; volta ao tronco anterior */

            if (!pilhaVazia(Pilha))
            {   semSaida=0;
                desemPilha(&Pilha, &dado);

                while ((dado.tronco==0)&&(!pilhaVazia(Pilha)))
                        desemPilha(&Pilha, &dado);
                if (dado.tronco==0)
                    semSaida=1;
                else
                {
                    lin=dado.lin;
                    col=dado.col;
                    retrocesso=1;
                }
            }

        }

    }

    if (cheguei)
    {
        printf("\nCaminho Encontrado!\n");

    /*  while (!pilhaVazia(Pilha))
        {
            desemPilha(&Pilha, &dado);
            printf("\n[%d,%d]",dado.lin, dado.col);
        }
    */

        imprimeCaminho();
    }
    else printf("\nCaminho nao Encontrado!\n");

}
