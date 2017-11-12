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

/*  Fonction : AssignUsers(...)
 *  Creer une matrice qui contient le nombre d'utilisateur lignes
 *  et pour chaque utilisateur on atribut une ligne de la matrice d'hadamard
*/

int ** AssignUsers(int nbUser, int taille_mat, int ** mHadamard){
  int i, j;
  int User_courant;

  int ** motcodeUser = (int **) malloc(nbUser * sizeof(int *));
	int row;

	for (row = 0; row <= nbUser; row++) {
  	motcodeUser[row] = (int *)malloc(taille_mat * sizeof(int));
  }

  for(User_courant = 1,i = 0; User_courant <= nbUser; User_courant++, i++)
      for(j = 0; j < taille_mat; j++)
        motcodeUser[User_courant][j] = mHadamard[i][j];

  return motcodeUser;
}

/*  Fonction : MotCodeAffichage(...)
 *  afficher les mots code de tous les utilisateurs
*/
void MotCodeAffichage(int ** motCode, int taille_mat, int nbUser){
  int i;
  int user;

  for(user = 1; user <= nbUser; user++){
    if(user < 10)
      printf("Mot code du User  %i : ", user);
    else printf("Mot code du User %i : ", user);

    for(i = 0; i < taille_mat; i++)
      if(motCode[user][i] == -1)
        printf("0 ");
      else printf("%i ", motCode[user][i]);
    printf("\n");
  }

    printf("\n\n");
}

/*  Fonction : CodageSeq(...)
 *  Creer une matrice qui contient le codage de chaque sequence
 *  envoyer par l'utilisateur
*/
int ** CodageSeq(int ** motCode, int user,int seq[], int taille_seq, int taille_ligne){
  int i, j;

  int ** codeSeq = (int **) malloc(taille_seq * sizeof(int *));
	int row;

	for (row = 0; row < taille_seq; row++) {
  	codeSeq[row] = (int *)malloc(taille_ligne * sizeof(int));
  }

  for(i = 0; i < taille_seq; i++){        /* pour chaque element binaire de la sequence */
    if(seq[i] == 1){                      /* si l'element binaire est 1 on ne change pas le mot code*/
      for(j = 0; j < taille_ligne; j++)
        codeSeq[i][j] = motCode[user][j];
    }else {                               /* si l'element binaire est -1 on inverse le mot code*/
      for(j = 0; j < taille_ligne; j++)
        codeSeq[i][j] = -motCode[user][j];
    }
  }
  return codeSeq;
}

/*  Fonction : CodageSeqAffichage(...)
 *  Affiche la matrice du codage de la sequence
*/
void CodageSeqAffichage(int ** codeSeq, int taille_ligne, int taille_seq){
  int i , j;

  for(i = 0; i < taille_seq; i++)
    for(j = 0; j < taille_ligne; j++)
      if(codeSeq[i][i] == -1)
        printf("0 ");
      else printf("%i ", codeSeq[i][i]);
    printf("\n");

}
