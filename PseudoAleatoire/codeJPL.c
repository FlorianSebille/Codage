#include <stdio.h>
#include <stdlib.h>

#include "codeLM.h"

void afficherResultat(int * resultat){
  int i;
  for(i = 0; i < L; i++){
    printf("%i ",resultat[i]);
  }
}

int pgcd(int nombre1, int nombre2)
{
  if(nombre2==0)
     return nombre1;
  return pgcd(nombre2, nombre1%nombre2);
}

int nb_premier(int nombre1, int nombre2, int nombre3){
  if (pgcd(nombre1, nombre2) == 1 && pgcd(nombre2, nombre3))
    return 1;
  return 0;
}

void actionJpl(int * vecteur1, int nb_elem_vecteur1, int * vecteur2, int nb_elem_vecteur2, int * vecteur3, int nb_elem_vecteur3, int * tab){

  int i;
  int resultat1[L];
  int resultat2[L];
  int resultat3[L];

  actionRegistre(vecteur1, nb_elem_vecteur1, resultat1);
  actionRegistre(vecteur2, nb_elem_vecteur2, resultat2);
  actionRegistre(vecteur3, nb_elem_vecteur3, resultat3);

  printf("Première séquence\n\n");
  afficherResultat(resultat1);
  printf("\n\n");
  printf("Deuxième séquence\n\n");
  afficherResultat(resultat2);
  printf("Troisième séquence\n\n");
  afficherResultat(resultat3);
  printf("\n\n");
  printf("Séquence finale (XOR)\n\n");

  /*XOR entre le premier et le deuxieme code LM*/
  for(i = 0; i < L; i++){
    tab[i] = resultat1[i] ^ resultat2[i];
  }

  /*XOR entre le resultat des deux premier et le troisième code LM*/
  for(i = 0; i < L; i++){
    tab[i] = tab[i] ^ resultat2[i];
    printf("%i ",tab[i]);
  }
}
