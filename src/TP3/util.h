/* util.h */
/* 
utilitaires de saisie et de generation aleatoire de chaines
de caracteres et d'entiers
*/

#ifndef UTIL_H
#define UTIL_H


/* saisie de chaine */
char *saisie_chaine(char *chaine, int taille);


/* generation de chaine aleatoire de 'taille' majuscules */
char *alea_chaine(char *chaine, int taille);

/* saisie d'entier */
int saisie_int(int *pn);

/* generation d'un entier aleatoire entre a (inclus) et b(exclu) */
void alea_int(int *pn, int a, int b);

#endif
