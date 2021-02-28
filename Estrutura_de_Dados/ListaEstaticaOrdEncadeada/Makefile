# Author: Lucas Pacheco

SCRIPT1 = ListaOrdEncad
SCRIPT2 = Aplicacao_Lista_OrdEncad

SRC = "../ListaOrdEncad.h"

CC  = gcc 
OBJFLAG = -c
EXEFLAG = -o
HS_FLAG = -I
MTHFLAG = -lm

all:
	$(CC) $(OBJFLAG) $(SCRIPT1).c $(HS_FLAG) $(SRC)
	$(CC) $(OBJFLAG) $(SCRIPT2).c $(HS_FLAG) $(SRC)
	$(CC) $(EXEFLAG) $(SCRIPT2) $(SCRIPT1).o $(SCRIPT2).o

clean:
	rm ./*.o
	clear

cleanAll:
	rm ./*.o
	rm $(SCRIPT2)
	clear