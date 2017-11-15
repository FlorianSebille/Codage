#include <stdlib.h>
#include <stdio.h>

#include "matrice.h"

/*  Fonction : MatriceCreer(...)
 *  Création d'une matrice en dynamique
 *  avec le nombre de lignes et de colones en paramètre
*/
int ** MatriceCreer(int lignes, int colonnes){
  int i;
  int ** mat = (int **) malloc(sizeof(int*)*lignes);
  for(i=0;i<lignes;i++){
    mat[i] = (int *) malloc(sizeof(int)*colonnes);
  }
  return mat;
}

/*  Fonction : MatriceDetruit(...)
 *  destruction d'une matrice en dynamique
 *  avec la matrice et le nombre de lignes en paramètre
*/
void MatriceDetruire(int ** mat, int lignes){
  int i;

  for (i = 0; i < lignes; i++) {
    free(mat[i]);
  }

  free(mat);
}

/*  Fonction : MatriceAffichage(...)
 *  affichage d'une matrice
 *  avec la matrice et le nombre de lignes et de colones en paramètre
*/
void MatriceAffichage(int ** mat, int lignes, int colones){
  int i , j;

  for(i = 0; i < lignes; i++){
    for(j = 0; j < colones; j++)
      if(mat[i][j] == -1)
        printf("0 ");
      else printf("%i ", mat[i][j]);
    printf("\n");
  }
}
