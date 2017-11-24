
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "codeLM.h"

/* On donne au codeur JPL une matrice qui contient ses polynomes générateur

Ex: On souhaite créer un codeur JPL avec des séquences LM généré à partir de [2,1], [3,1] et [5,2]

Matrice donné au codeur JPL:

		2 | 2 | 1
		2 | 3 | 1
		2 | 5 | 2

La première colonne correspond à la taille du vecteur associé à la ligne

*/


//Retourne le vecteur son son indice de taille
//Ex:	[4,5,4,2,1] -> [5,4,2,1]
//	[2,5,2] -> [5,2]
int * troncVecteur(int * vecteur){
	int i;
	int * sortie = malloc(vecteur[0]* sizeof(int));
	for(i = 0; i < vecteur[0]; i++){
		sortie[i] = vecteur[i+1];
	}
	return sortie;
}


//Retourne la taille de la plus grande séquence possible -> max(L1,L2..Ln)
int lg_max_sequence(int ** matrice, int taille_matrice){
  int max = matrice[0][1];
	int i;
  	for(i = 1; i < taille_matrice; i++){
   		if(max < matrice[i][1]) max = matrice[i][1];
  	}
  	return (pow(2,max)-1);
}

//Retourne la taille de la séquence finale -> L1*L2*..*Ln
int lg_final_sequence(int ** matrice, int taille_matrice){
	int cpt = 1;
	int i;
	for(i = 0; i < taille_matrice; i++){
		cpt = cpt * pow(2,matrice[i][1])-1;
	}
	return cpt;
}

void fillSequence(int * sequence, int nb_colonnes, int taille_init){
	int i, j;
	for(i = taille_init, j = 0; i < nb_colonnes; i++, j++){
		if(j == 3) j = 0;
		sequence[i] = sequence[j];
	}
}

//Retourne une séquence dans un tableau issu d'une matrice avec les vecteurs générateurs des séquences LM associés
int * actionJPL(int ** matrice, int taille_matrice){

	int i,j;

	int lg_final = lg_final_sequence(matrice,taille_matrice);
	int matrice_resultat[taille_matrice][lg_final];
	int * tab_final = malloc(sizeof(int)*lg_final);

	for(i = 0; i < taille_matrice; i++){
		actionRegistre(troncVecteur(matrice[i]),matrice[i][0],matrice_resultat[i]);
	}

	for(i = 0; i < taille_matrice; i++){
		fillSequence(matrice_resultat[i],lg_final,pow(2,matrice[i][0]-1));
	}

	for(i = 0; i < lg_final; i++){
		tab_final[i] =  matrice_resultat[0][i]  ^ matrice_resultat[1][i];
	}

	for(j = 2; j < taille_matrice; j++){
		for(i = 0; i < lg_final; i++){
			tab_final[i] = tab_final[i] ^ matrice_resultat[j][i];
		}
	}

	return tab_final;

}
