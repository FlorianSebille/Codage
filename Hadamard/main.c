#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "hadamard.h"
#include "canal.h"

int main(){

  int nUsers, tailleH, mot_longueur, i, j;
  int ** mHadamard;
  int ** MotCodeUsers;
  int ** Mots;
  int ** Entree_Canal;
  int ** Sortie_Canal;
  int ** MotsDecoder;

  printf("***** Codeur de Hadamard *****\n\n");

  printf("Saisir le nombre d'utilisateurs: ");
  scanf("%i",&nUsers);
  printf("\n");

  printf("Saisir la longueur des mots: ");
  scanf("%i",&mot_longueur);
  printf("\n");

  Mots = SaisirMot(nUsers,mot_longueur);

  printf("\nDefinition d'une taille pour la matrice d'Hadamard ...\n\n");
  tailleH = TailleMatrice(nUsers);
  sleep(1);

  printf("Création de la matrice d'Hadamard ...\n\n");
  mHadamard = MatHadamardCreer(tailleH);
  sleep(1);

  printf("Affichage de la matrice créée:\n\n");
  MatriceAffichage(mHadamard, tailleH, tailleH);

  printf("\nAssignation des mots codes à chaque utilisateur ...\n\n");
  MotCodeUsers = AssignUsers(nUsers, tailleH, mHadamard);
  MatriceAffichage(MotCodeUsers, nUsers, tailleH);

  sleep(2);

  printf("\nCréation de la matrice avec les mots codés ...\n\n");

  Entree_Canal = CodageSeq(MotCodeUsers,Mots,mot_longueur,tailleH,nUsers);
  MatriceAffichage(Entree_Canal,nUsers, mot_longueur * tailleH);
  sleep(2);

  printf("\nPassage dans le canal ...\n\n");
  Sortie_Canal = MatriceCreer(nUsers, (mot_longueur * tailleH));
  Sortie_Canal = canalParfait(Entree_Canal);
  sleep(2);

  printf("Affichage des mots decodé de chaque utilisateur: \n\n");
  /*
    *
    * Fonction(s) à faire
    *
  */
  MotsDecoder = Decodage(Entree_Canal, nUsers, MotCodeUsers, tailleH, mot_longueur);
  MatriceAffichage(MotsDecoder,nUsers, mot_longueur);
  sleep(2);

  printf("\nDestruction de la matrice avec les mots codés ... \n\n");
  MatriceDetruire(MotsDecoder,nUsers);
  MatriceDetruire(Entree_Canal,nUsers);
  MatriceDetruire(MotCodeUsers,nUsers);
  MatriceDetruire(Mots,nUsers);

  sleep(2);

  printf("Destruction de la matrice d'Hadamard ...\n\n");
  MatriceDetruire(mHadamard,tailleH);
  sleep(1);

  printf("***** Fin du codeur *****\n");

}
