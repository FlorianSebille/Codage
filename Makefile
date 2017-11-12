#==================
# Makefile Codage
#==================

#-------------
# Executables
#-------------

hadamard : main.o hadamard.o canal.o
	gcc main.o hadamard.o canal.o -o hadamard

main.o : main.c
	gcc -c main.c -o main.o

#----------
# Modules
#----------

# CANAL
# "Parfait"

canal.o : canal.c canal.h
	gcc -c canal.c -o canal.o

#	Générateur Matrice Hadamard
#

hadamard.o : hadamard.c hadamard.h
	gcc -c hadamard.c -o hadamard.o


#----------------------------
# Gestion generale du projet
#----------------------------

all : hadamard

clean :
		rm *.o
