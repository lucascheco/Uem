#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MY_LIB.h"

int modo(Flag flag, FILE *arq_source, FILE *arq_destination)
{
  if (flag == IMPORT)
  {
    importaArq(arq_source, arq_destination);
    return flag;
  }
  else if(flag == OPER)
  {
    return flag;
  }
  else
  {
    return 0;
  }
}

int importaArq(FILE *arq_source, FILE *arq_destination)
{
  char c;
  int  cont = 0;
  
  while ((c = fgetc(arq_source)) != EOF)
  {
    fwrite(&c, sizeof(char), 1,arq_destination);
    cont++;
  }

  return cont;
}
