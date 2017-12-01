
/* Fonctions utiles à la génération d'une code JPL */

int pgcd(int nombre1, int nombre2);
int ** matriceRegistre(int * taille_matrice);
int * troncVecteur(int * vecteur);
int lg_max_sequence(int ** matrice, int taille_matrice);
int lg_final_sequence(int ** matrice, int taille_matrice);
void fillSequence(int * sequence, int nb_colonnes, int taille_init);
int * actionJPL(int ** matrice, int taille_matrice);
