#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hadamard.h"
#include "canal.h"


int main(){

  int nUsers, tailleH;
  int ** mHadamard;

  printf("***** Codeur de Hadamard *****\n\n");

  printf("Saisir le nombre d'utilisateurs: ");
  scanf("%i",nUsers);
  printf("\n");

  printf("Definition d'une taille pour la matrice d'Hadamard ...\n\n")
  tailleH = TailleMatrice(nUsers);
  sleep(1);

  printf("Création de la matrice d'Hadamard ...\n\n");
  mHadamard = MatHadamardCreer(tailleH);
  sleep(1);

  printf("Affichage de la matrice créée:\n\n")
  MatHadamardAfficher(mHadamard,tailleH);

  printf("Assignation des mots codes à chaque utilisateur ...\n\n")
  /*
    *
    * Fonction à faire
    *
  */
  sleep(1);

  printf("Création de la matrice avec les mots codés ...\n\n")
  /*
    *
    * Fonction à faire
    *
  */
  sleep(1);

  printf("Passage dans le canal ...\n\n")
  /*
    *
    * Fonction à faire
    *
  */
  sleep(1);

  printf("Affichage des mots decodé de chaque utilisateur: \n\n")
  /*
    *
    * Fonction(s) à faire
    *
  */
  sleep(1);

  printf("Destruction de la matrice avec les mots codés ... \n\n")
  /*
    *
    * Fonction à faire
    *
  */
  sleep(1);

  printf("Destruction de la matrice d'Hadamard ...");
  MatHadamardSupp(mHadamard,taille);
  sleep(1);

  printf("***** Fin du codeur *****");

}
