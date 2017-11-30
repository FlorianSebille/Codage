#include "codeLM.h"
#include "codeGold.h"
#include <stdio.h>


void afficherResultat(int * resultat){
  /* Affiche la sortie d'un code LM */

  int i;
  for(i = 0; i < L; i++){
    printf("%i ",resultat[i]);
  }
}

void actionGold(int * vecteur1, int nb_elem_vecteur1, int * vecteur2, int nb_elem_vecteur2, int * tab){
  /* Simule un générateur de code de Gold */

  int i;
  int resultat1[L];
  int resultat2[L];

  actionRegistre(vecteur1, nb_elem_vecteur1, resultat1);
  actionRegistre(vecteur2, nb_elem_vecteur2, resultat2);

  printf("Première séquence\n\n");
  afficherResultat(resultat1);
  printf("\n\n");
  printf("Deuxième séquence\n\n");
  afficherResultat(resultat2);
  printf("\n\n");
  printf("Séquence finale (XOR)\n\n");

  for(i = 0; i < L; i++){
    tab[i] = resultat1[i] ^ resultat2[i];
    printf("%i ",tab[i]);
  }

}
