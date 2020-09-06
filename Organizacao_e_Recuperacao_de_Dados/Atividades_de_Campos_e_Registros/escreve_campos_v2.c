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

int main()
{
    int   i = -1;
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
        /* Reset the i counter to 0 */
        fprintf(stdout, "%s", menu[i = (i == 4) ? 0 : ++i]);
        gets(str);
        
        if(strlen(str) > 1)
            strcat(str, "|");
        
        fwrite(str, strlen(str), 1, fp);
    
    } while (strlen(str) > 2);

    fwrite("\0", sizeof(char), 1 , fp);
   
    free(str);
    fclose(fp);

    return 0;
}