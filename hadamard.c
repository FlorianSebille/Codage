#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void MatHadamardAfficher(int ** Matrice, int taille){

	int i, j;

	for(i = 0; i < taille; i++){
		for(j = 0; j < taille; j++){
			printf("%i ");
		}
		printf("\n");
	}

}

int ** MatHadamardRenverser( int ** Matrice; int taille){

	int i,j;

	for(i = 0; i < taille; i++)
		for(j = 0; j < taille; j++)
			Matrice[i][j] = Matrice[i][j] * (-1);

	return Matrice;
}

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

	int indice = 1;

	int taille = TailleMatrice(NbUtilisateur);

	int Mat[taille][taille];

	Mat[0][0] = 1;

	int i = 0;
	int j = 0;

	while(indice < taille){

		for(; i < indice; i++){
			for(; < indice; j++){
				if(i >= indice && j >= indice){
					indice[i][j] = indice[i][j] * (-1);
					else indice[i][j] = indice[0][0];
				}
		}

		i = indice +1;
		j = indice +1;
		indice = indice * 2 - 1;

	}
}

int main(){



	return 1;

}
