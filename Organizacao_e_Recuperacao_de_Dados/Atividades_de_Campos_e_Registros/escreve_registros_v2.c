/*
    * Author: Lucas Matheus Silva Pacheco
    * RA:     112-686
    * Date:   30/08/2020
    
    Description:
        * Writing data from people repeatedly until "empty" name is entered.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REGSIZE 5

int main()
{
    int   i = -1, cont_reg = 0;
    char *str;
    char  menu[5][40] = {
          "Digite o nome     : ",
          "Digite o sobrenome: ",
          "Digite o endereco : ",
          "Digite a cidade   : ",
          "Digite o estado   : "
    };

    FILE *fp;

    str = (char *)malloc(sizeof(char));
    
    fp = fopen("texto.txt", "wb");

    do
    {
        if (cont_reg == 0)
            fprintf(stdout, "\nESCREVER REGISTRO: \n");
        
        /* Reset the i counter to 0 */
        fprintf(stdout, "%s", menu[i = (i == 4) ? 0 : ++i]);
        gets(str);
        
        if(strlen(str) > 1)
            strcat(str, "|");
        
        fwrite(str, strlen(str), 1, fp);
        
        cont_reg++;
        
        if (cont_reg == 5)
            cont_reg = 0;

    } while (strlen(str) > 2);

    fwrite("\0", sizeof(char), 1 , fp);
   
    free(str);
    fclose(fp);

    return 0;
}