# Author: Lucas Pacheco

SCRIPT1 = filaComPilha
SCRIPT2 = Aplicacao_Fila_com_Pilha
SCRIPT3 = ../PilhaEstatica/PilhaEstatica
SCRIPT4 = PilhaEstatica


SRC  = ../filaComPilha.h
SRC2 = ../Estrutura_de_Dados/PilhaEstatica/PilhaEstatica

CC  = gcc 
OBJFLAG = -c
EXEFLAG = -o
HS_FLAG = -I
MTHFLAG = -lm

all:
	$(CC) $(OBJFLAG) $(SCRIPT3).c $(HS_FLAG) $(SRC2).h
	$(CC) $(OBJFLAG) $(SCRIPT1).c $(HS_FLAG) $(SRC) $(HS_FLAG) $(SRC2).h
	$(CC) $(OBJFLAG) $(SCRIPT2).c $(HS_FLAG) $(SRC)
	$(CC) $(EXEFLAG) $(SCRIPT2) $(SCRIPT1).o $(SCRIPT2).o $(SCRIPT4).o

clean:
	rm ./*.o
	clear

cleanAll:
	rm ./*.o
	rm $(SCRIPT2)
	clear
