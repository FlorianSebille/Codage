#include <stdlib.h>
#include <stdio.h>

#include "matrice.h"

int ** MatriceCREER(int colones, int lignes){
 int i;
 int ** mat = (int **) malloc(sizeof(int*)*lignes);
 for(i=0;i<lignes;i++){
  mat[i] = (int *) malloc(sizeof(int)*colones);
 }
 return mat;
}

void MatriceDetruit(int ** mat, int lignes){
    int i;
    
    for (i = 0; i < lignes; i++) {
         free(mat[i]);
    }

    free(mat);
}

void MatriceAffichage(int ** mat, int lignes, int colones){
  int i , j;

  for(i = 0; i < lignes; i++)
    for(j = 0; j < colones; j++)
      if(mat[i][j] == -1)
        printf("0 ");
      else printf("%i ", mat[i][j]);
    printf("\n");
}
