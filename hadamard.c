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

	int ** M = MatriceCreer(taille, taille);

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

/*  Fonction : AssignUsers(...)
 *  Creer une matrice qui contient le nombre d'utilisateur lignes
 *  et pour chaque utilisateur on atribut une ligne de la matrice d'hadamard
*/
int ** AssignUsers(int nbUser, int taille_mat, int ** mHadamard){
  int i, j;
  int User_courant;

  int ** motcodeUser = MatriceCreer(taille_mat, nbUser+1);

  for(User_courant = 1,i = 0; User_courant <= nbUser; User_courant++, i++)
      for(j = 0; j < taille_mat; j++)
        motcodeUser[User_courant][j] = mHadamard[i][j];

  return motcodeUser;
}


/*  Fonction : CodageSeq(...)
 *  Creer une matrice qui contient le codage de chaque sequence
 *  envoyer par l'utilisateur
*/
int ** CodageSeq(int ** motCode, int user,int seq[], int taille_seq, int taille_ligne){
  int i, j;

  int ** codeSeq = MatriceCreer(taille_ligne, taille_seq);

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
