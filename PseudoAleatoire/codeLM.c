#define VALEUR_INIT 1
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


int ** creerTableEtages(int nombre_etages){

  /* Créer une table à n étages pour un registre */

  int i;
  int ** table = (int **) malloc(sizeof(int*)*nombre_etages);
  for(i=0;i<nombre_etages;i++){
    table[i] = (int *) malloc(sizeof(int)*ENTREE_SORTIE_REGISTRE);
  }
  return table;

}

void initRegistre(int ** table, int nombre_etages){

  /* Initialise la table du registre */

  int i, j;
  for(i = 0; i < nombre_etages; i++){
    for(j = 0; j < ENTREE_SORTIE_REGISTRE; j++){}
      if(j == 3)
        table[i][j] == VALEUR_INIT;
      if(i == nombre_etages - 1 && j == 1)
  }
}

void actionDecalage(int ** table, int * tableau_sortie){

  /* Actionne le registre pour 1 décalage */

}
