#include <stdio.h>
#include <stdlib.h>

#include "../Matrice/matrice.h"

#include "codeLM.h"
#include "codeGold.h"

#define LONG_REGISTRE 20

int pgcd(int nombre1, int nombre2){
  if(nombre2==0)
     return nombre1;
  return pgcd(nombre2, nombre1%nombre2);
}

int ** matriceRegistre(){

    int nb_seq;
    int i, j;
    int nb_etage;
    int entree;
    int verif = 0;

    printf("Combien de séquences voulez vous ?\nNombre de séquences : ");
    scanf("%i",&nb_seq);

    int ** matrice = MatriceCreer(nb_seq, LONG_REGISTRE);

    printf("veuillez saisir les pôlynomes de génération\n");
    for(i = 0, j = 1; i < nb_seq; i++, j=1, verif = 0){

      do{
        printf("\nPolynôme %i : \nnombre d'étage : ",i+1);
        scanf("%i", &nb_etage);
        if(i != 0 && pgcd(nb_etage, matrice[i-1][j]) == 1)
          verif = 1;
        else if(i != 0)
          printf("ERREUR les nombres d'étages ne sont pas premier entre eux !!!\nveuiller recommencer le polynôme %i\n",i+1);
      }while(!verif && i != 0);

      matrice[i][j] = nb_etage;


      printf("saisir les entrees (Porte XOR) / Saisir -1 pour terminer\n");
      do{
        printf("entree : ");
        scanf("%i", &entree);

        if(entree != -1){
          j++;
          matrice[i][j] = entree;
        }

      }while(entree != -1);

      matrice[i][0] = j;

    }
    MatriceAffichage(matrice, nb_seq, LONG_REGISTRE);
    return matrice;
}

/*void actionJpl(){

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

  XOR entre le premier et le deuxieme code LM
  for(i = 0; i < L; i++){
    tab[i] = resultat1[i] ^ resultat2[i];
  }

  XOR entre le resultat des deux premier et le troisième code LM
  for(i = 0; i < L; i++){
    tab[i] = tab[i] ^ resultat3[i];
    printf("%i ",tab[i]);
  }
}
*/
