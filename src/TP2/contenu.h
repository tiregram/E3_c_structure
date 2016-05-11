#ifndef G__CONTENU
#define G__CONTENU

#define TAILLEMAX 10

struct contenu {
  char tab[TAILLEMAX];
};

typedef struct contenu contenu;

void print_contenu  (contenu * contenu_to_print);

void saisir_contenu (contenu * contenu_to_remplir);

int comparer_contenu(contenu *pc1, contenu *pc2);

void affecte_contenu(contenu * dest,contenu * source);

int comparer_chaine(contenu*con,char * chaine );

#endif
