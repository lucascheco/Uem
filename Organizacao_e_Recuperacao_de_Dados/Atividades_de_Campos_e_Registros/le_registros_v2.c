/*
    * Author: Lucas Matheus Silva Pacheco
    * RA:     112-686
    * Date:   30/08/2020
    
    Description:
        * This program reads Registers with a fixed number of fields.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This program reads Registers with a fixed number of fields */
#define TAM_REG 5 /* Number of fields */

/* Register reading function prototype*/
int get_reg(FILE *arq, int *i);

int main()
{
    FILE *fp;
    int   i    = 1, 
          flag = 1,
          cont_reg = 0;

    if ((fp = fopen("texto.txt", "rb")) == NULL)
        exit(1);

    for (; cont_reg < TAM_REG;)
    {
        while (flag)
        {
            flag = get_reg(fp, &i);

            if (flag)
            {
                fprintf(stdout, "\n");
                cont_reg++;
            }
        }

    }

    fclose(fp);
    
    return 0;
}


/* Register reading function */
int get_reg(FILE *arq, int *i)
{   
    char c;
    int  cond = 0; /* Condition to print "campo# i" */
    int register_count = 1;
    
    do 
    {

        fread(&c, sizeof(char), 1, arq);    

        if(c != '\0' && cond == 0)
        {
            if (*i == 1)
                fprintf(stdout, "Registro %d: \n", register_count++);   
            
            fprintf(stdout, "\tcampo #%3d: ", *i);
            
            *i = (*i == TAM_REG) ? 1 : ++(*i);
        }

        if (c != '|')
        {
            fprintf(stdout, "%c", c); 
            cond++;        
        }

    } while (c != '|' && c != '\0');

    if (c == '\0')
        return 0;
    else
        return 1;
}
