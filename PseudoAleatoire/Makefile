#==================
# Makefile Codage
#==================

#-------------
# Executables
#-------------

aleatoire : main.o codeLM.o codeGold.o codeJPL.o matrice.o
	gcc main.o codeLM.o codeGold.o codeJPL.o matrice.o -o aleatoire -lm

main.o : main.c
	gcc -c main.c -o main.o

#----------
# Modules
#----------

codeJPL.o : codeJPL.c codeJPL.h
	gcc -c codeJPL.c -o codeJPL.o

codeLM.o : codeLM.c codeLM.h
	gcc -c codeLM.c -o codeLM.o

codeGold.o : codeGold.c codeGold.h
	gcc -c codeGold.c -o codeGold.o

#	Fonctions generales sur les matrices en dynamique
#

matrice.o : ../Matrice/matrice.c ../Matrice/matrice.h
	gcc -c ../Matrice/matrice.c -o matrice.o

#----------------------------
# Gestion generale du projet
#----------------------------

all : aleatoire

clean :
	rm *.o
