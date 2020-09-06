/*
    * Author: Lucas Matheus Silva Pacheco
    * RA:     112-686
    * Date:   30/08/2020

    Description:
        * Read data from a file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Field reading function prototype*/
int get_field(FILE *arq, int *i);

int main()
{
    FILE *fp;
    int   i    = 1, 
          flag = 1;

    if ((fp = fopen("texto.txt", "rb")) == NULL)
        exit(1);

    while (flag)
    {
        flag = get_field(fp, &i);
        if (flag)
            fprintf(stdout, "\n");
    }

    fclose(fp);
    
    return 0;
}


/* Field reading function */
int get_field(FILE *arq, int *i)
{   
    char c;
    int  cond = 0; /* Condition to print "campo# i" */
    
    do 
    {   
        fread(&c, sizeof(char), 1, arq);    

        if(c != '\0' && cond == 0)
            fprintf(stdout, "campo #%3d: ", (*i)++);
        
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
