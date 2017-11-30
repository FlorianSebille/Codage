#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../Matrice/matrice.h"

#include "codeLM.h"
#include "codeGold.h"

#define LONG_REGISTRE 20

/* On donne au codeur JPL une matrice qui contient ses polynomes générateur

Ex: On souhaite créer un codeur JPL avec des séquences LM généré à partir de [2,1], [3,1] et [5,2]

Matrice donné au codeur JPL:

		2 | 2 | 1
		2 | 3 | 1
		2 | 5 | 2

La première colonne correspond à la taille du vecteur associé à la ligne (nbEtages + nbPorteXOR)

*/

int pgcd(int nombre1, int nombre2){
  if(nombre2==0)
     return nombre1;
  return pgcd(nombre2, nombre1%nombre2);
}

int ** matriceRegistre(int * taille_matrice){

    int i, j;
    int nb_etage;
    int entree;
    int verif = 0;

    printf("Combien de séquences voulez vous ?\nNombre de séquences : ");
    scanf("%i",taille_matrice);

    int ** matrice = MatriceCreer(*taille_matrice, LONG_REGISTRE);

    printf("veuillez saisir les pôlynomes de génération\n");
    for(i = 0, j = 1; i < *taille_matrice; i++, j=1, verif = 0){

      do{
        printf("\nPolynôme %i : \nnombre d'étage : ",i+1);
        scanf("%i", &nb_etage);
        if(i != 0 && pgcd(nb_etage, matrice[i-1][j]) == 1)
          verif = 1;
        else if(i != 0)
          printf("ERREUR les nombres d'étages ne sont pas premier entre eux !!!\nveuiller recommencer le polynôme %i\n",i+1);
      }while(!verif && i != 0);

      matrice[i][j] = nb_etage;


      printf("saisir les entrees (Porte XOR) / Saisir -1 pour terminer\n");
      do{
        printf("entree : ");
        scanf("%i", &entree);

        if(entree != -1){
          j++;
          matrice[i][j] = entree;
        }

      }while(entree != -1);

      matrice[i][0] = j;

    }
    MatriceAffichage(matrice, *taille_matrice, LONG_REGISTRE);
    return matrice;
}


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
		cpt = cpt * (pow(2,matrice[i][1]) -1);
	}
	return cpt;
}

void fillSequence(int * sequence, int nb_colonnes, int taille_init){
	int i, j;
	for(i = taille_init, j = 0; i < nb_colonnes; i++, j++){
		if(j == taille_init) j = 0;
		sequence[i] = sequence[j];
	}
}


//Simulateur d'un code JPL variable
//Retourne une séquence dans un tableau issu d'une matrice avec les vecteurs générateurs des séquences LM associés
int * actionJPL(int ** matrice, int taille_matrice){

	int i,j;

	int lg_final = lg_final_sequence(matrice,taille_matrice);
	int ** matrice_resultat = MatriceCreer(taille_matrice,lg_final);

	int * tab_final = malloc(sizeof(int)*lg_final);

	for(i = 0; i < taille_matrice; i++){
		actionRegistre(troncVecteur(matrice[i]),matrice[i][0],matrice_resultat[i]);
	}

	for(i = 0; i < taille_matrice; i++){
		fillSequence(matrice_resultat[i],lg_final,pow(2,matrice[i][1]-1));
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
