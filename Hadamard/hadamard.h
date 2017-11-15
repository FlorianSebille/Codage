
#include "matrice.h"

/* Fonctions utiles à la manipulation d'une matrice Hadamard */

int TailleMatrice(int);

int ** MatHadamardCreer(int);

int ** AssignUsers(int, int , int **);

int ** CodageSeq(int **, int **, int, int, int);

int ** SaisirMot(int, int);

int ** Decodage(int **, int, int **, int, int);

void DecoderMot(int *, int, int **, int, int, int, int *);
