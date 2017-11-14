#==================
# Makefile Codage
#==================

#-------------
# Executables
#-------------

hadamard : main.o hadamard.o canal.o matrice.o
	gcc main.o hadamard.o canal.o matrice.o -o hadamard

main.o : main.c
	gcc -c main.c -o main.o

#----------
# Modules
#----------

# CANAL
#

canal.o : canal_parfait.c canal.h
	gcc -c canal_parfait.c -o canal.o

#
# "Parfait"

canal.h : canal_parfait.h
		touch canal.h

#	Générateur Matrice Hadamard
#

hadamard.o : hadamard.c hadamard.h
	gcc -c hadamard.c -o hadamard.o

#	Fonctions generales sur les matrices en dynamique
#

matrice.o : matrice.c matrice.h
	gcc -c matrice.c -o matrice.o


#----------------------------
# Gestion generale du projet
#----------------------------

all : hadamard

clean :
		rm *.o
