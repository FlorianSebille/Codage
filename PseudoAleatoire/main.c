#include <stdlib.h>
#include <stdio.h>

#include "codeLM.h"
#include "codeGold.h"
#include "codeJPL.h"



int main(){

  int taille_matrice;
  int i;

  //Creation de vecteurs générateurs de code LM
  int ** matrice = matriceRegistre(&taille_matrice);

  //Calcul de la longueur finale (non-maximale) du code JPL associé à la matrice
  int long_tab = lg_final_sequence(matrice, taille_matrice);

  //Génération du code JPL associé à la matrice
  int * tab =  actionJPL(matrice, taille_matrice);

  //Affichage finale
  printf("\n\n");
  for(i = 0;  i < long_tab; i++)
    printf("%i ",tab[i]);
}
