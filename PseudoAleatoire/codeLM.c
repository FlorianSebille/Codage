#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ENTREE_SORTIE_REGISTRE 4

/*
*   colonne 0 : Sortie XOR
*   colonne 1 : Entree XOR
*   colonne 2 : Sortie Etage
*   colonne 3 : Entree Etage
*/

/*
*   ligne 0:        Premier étage du registre
*   ligne 1..n-2:   N ième étages du registre
*   ligne n-1       Dernier étage du registre -> sortie
*/

void afficherTable(int * table, int * vecteur){

  /* Affiche une table en fonction de sa taille */

  int i;
  for(i = 0; i < vecteur[0]; i++){
    printf("%i ",table[i]);
  }
}

void initRegistre(int * table, int * vecteur){

  /* Initialise la table du registre */

  int i;
  for(i = 0; i < vecteur[0]; i++){
    table[i] = 1;
  }
}

void actionDecalage(int * table, int * vecteur, int nb_elem_vecteur, int * sortie){

  /* Actionne le registre pour 1 décalage */

  int i;
  int res_xor = table[vecteur[0]-1];
  (*sortie) = table[vecteur[0]-1];

  for(i = 1; i < nb_elem_vecteur; i++){                  // On effectue un XOR entre tous les étages indiqués
    res_xor = res_xor ^ table[vecteur[i]-1];
  }

  for(i = vecteur[0] - 1; i > 0; i--){                  // On decale tous vers la droite
    table[i] = table[i-1];
  }

  table[0] = res_xor;                                   // On entre la nouvelle entrée

}

void actionRegistre(int * vecteur, int nb_elem_vecteur, int * resultat){

  //construit la table complète de sortie (resultat) à partir d'un vecteur elementaire */

  int i;
  int sortie;
  int table[vecteur[0]];

  initRegistre(table,vecteur);

  for(i = 0; i < (pow(2,vecteur[0]) - 1); i++){

    actionDecalage(table, vecteur, nb_elem_vecteur, &sortie);
    resultat[i] = sortie;
  }
}
