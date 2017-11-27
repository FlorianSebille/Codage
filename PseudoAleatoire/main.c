#include <stdlib.h>
#include <stdio.h>

#include "codeLM.h"
#include "codeGold.h"
#include "codeJPL.h"



int main(){

  /*int vecteur1[4] = {5,4,2,1};
  int vecteur2[2] = {5,2};
  int nb_elem_vecteur1 = (int)(sizeof(vecteur1)/sizeof(int));
  int nb_elem_vecteur2 = (int)(sizeof(vecteur2)/sizeof(int));
  int tab[L];

  actionGold(vecteur1,nb_elem_vecteur1,vecteur2,nb_elem_vecteur2,tab);*/
  int taille_matrice;
  int i;
  int ** matrice = matriceRegistre(&taille_matrice);

  //int tab[lg_final_sequence( matrice, taille_matrice)];
  int long_tab = lg_final_sequence( matrice, taille_matrice);
  int * tab =  actionJPL(matrice, taille_matrice);

  for(i = 0;  i < long_tab; i++)
    printf("case %i : %i\n", i+1, tab[i]);
}
