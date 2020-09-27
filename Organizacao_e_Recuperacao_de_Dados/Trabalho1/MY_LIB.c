#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MY_LIB.h"

int modo(Flag flag)
{
  if (flag == IMPORT)
  {

  }
  else if(flag == OPER)
  {

  }
  else
  {

  }
}

int importaArq(FILE arq_source, FILE arq_destination)
{
  char c;
  while ((c = fgetc(arq_source)) != EOF)
  {
    fwrite()
  }
}
