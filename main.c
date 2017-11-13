#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "hadamard.h"
#include "canal.h"

int main(){

  int nUsers, tailleH;
  int ** mHadamard;
  int ** motcodeUsers;
  int ** codageSequences;

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
  MatriceAffichage(mHadamard, tailleH, tailleH,1);

  printf("\nAssignation des mots codes à chaque utilisateur ...\n\n");
  motcodeUsers = AssignUsers(nUsers, tailleH, mHadamard);
  MatriceAffichage(motcodeUsers, nUsers+1, tailleH,0);

  sleep(2);

  printf("Création de la matrice avec les mots codés ...\n\n");

  sleep(2);

  printf("Passage dans le canal ...\n\n");
  /*
    *
    * Fonction à faire
    *
  */
  sleep(2);

  printf("Affichage des mots decodé de chaque utilisateur: \n\n");
  /*
    *
    * Fonction(s) à faire
    *
  */
  sleep(2);

  printf("Destruction de la matrice avec les mots codés ... \n\n");
  /*
    *
    * Fonction à faire
    *
  */
  sleep(2);

  printf("Destruction de la matrice d'Hadamard ...\n\n");
  MatHadamardSupp(mHadamard,tailleH);
  sleep(1);

  printf("***** Fin du codeur *****\n");

}
