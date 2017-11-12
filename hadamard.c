#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hadamard.h"

int TailleMatrice(int NbUtilisateur){

	int i = 2;
	int marq = 0;
	if( NbUtilisateur == 1) return 1;
	else{
		while(marq != 1){
			if(NbUtilisateur <= i)
				marq = 1;
			else
				i = i * 2;
		}
	}
	return i;

}

int ** MatHadamardCreer(int NbUtilisateur){

	int i, j;
	int indice = 2;
	int taille = TailleMatrice(NbUtilisateur);

	int ** M = (int **) malloc(taille * sizeof(int *));
	int row;

	for (row = 0; row < taille; row++) {
  	M[row] = (int *)malloc(taille * sizeof(int));
  }

	M[0][0] = 1;
	M[0][1] = 1;
	M[1][0] = 1;
	M[1][1] = -1;

	while(indice < taille){

		for(i = 0; i < indice * 2; i++){
			for(j = 0; j < indice * 2; j++){

				if(i >= indice && j < indice){
					M[i][j] = M[i-indice][j];
				}else if(j >= indice && i < indice){
					M[i][j] = M[i][j-indice];
				}else if (i >= indice && j >= indice){
					M[i][j] = M[i-indice][j-indice] * (-1);
				}
			}
		}

		indice = indice * 2;

	}

	return M;

}

void MatHadamardAfficher(int ** M, int taille){

	int i, j;

	for(i = 0; i < taille; i++){
		for(j = 0; j < taille; j++){
			if(M[i][j] == -1) printf("0 ");
			else printf("%d ",M[i][j]);
		}
		printf("\n");
	}
}

void MatHadamardSupp(int ** M, int taille){

	int row;

	for (row = 0; row < taille; row++) {
         free(M[row]);
    }

    free(M);
}
