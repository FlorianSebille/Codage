#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hadamard.h"
#include "canal.h"

/*  Fonction : AssignUsers(...)
 *  Creer une matrice qui contient le nombre d'utilisateur lignes
 *  et pour chaque utilisateur on atribut une ligne de la matrice d'adamard
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
      printf("mot code du User  %i :", user);
    else printf("mot code du User %i :", user);

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

int main(){

  int nUsers, tailleH;
  int ** mHadamard;
  int ** motcodeUsers;

  printf("***** Codeur de Hadamard *****\n\n");

  printf("Saisir le nombre d'utilisateurs: ");
  scanf("%i",&nUsers);
  printf("\n");

  printf("Definition d'une taille pour la matrice d'Hadamard ...\n\n");
  tailleH = TailleMatrice(nUsers);
  sleep(1);

  printf("Création de la matrice d'Hadamard ...\n\n");
  mHadamard = MatHadamardCreer(tailleH);
  sleep(1);

  printf("Affichage de la matrice créée:\n\n");
  MatHadamardAfficher(mHadamard,tailleH);

  printf("\nAssignation des mots codes à chaque utilisateur ...\n\n");
  /*
    *
    * Fonction à faire
    *
  */
  motcodeUsers = AssignUsers(nUsers, tailleH, mHadamard);
  /*MotCodeAffichage(motcodeUsers, tailleH, nUsers);*/

  sleep(1);

  printf("Création de la matrice avec les mots codés ...\n\n");
  /*
    *
    * Fonction à faire
    *
  */
  sleep(1);

  printf("Passage dans le canal ...\n\n");
  /*
    *
    * Fonction à faire
    *
  */
  sleep(1);

  printf("Affichage des mots decodé de chaque utilisateur: \n\n");
  /*
    *
    * Fonction(s) à faire
    *
  */
  sleep(1);

  printf("Destruction de la matrice avec les mots codés ... \n\n");
  /*
    *
    * Fonction à faire
    *
  */
  sleep(1);

  printf("Destruction de la matrice d'Hadamard ...\n");
  MatHadamardSupp(mHadamard,tailleH);
  sleep(1);

  printf("***** Fin du codeur *****\n");

}
