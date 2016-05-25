/* contenu.h */


typedef struct {
    char *nom;
  unsigned int birth;
  unsigned int died;

} contenu;

contenu * cree_contenu_alea(char *nom);
contenu * cree_contenu (char *nom,unsigned int birt,unsigned int died);

#define N 10
contenu * cree_alea_contenu() ;

void affiche_contenu(contenu *pc);

void libere_contenu(contenu *pc);

int compare_contenu(contenu *pc1, contenu* pc2);

int compare_valeur(contenu *pc1, contenu* pc2);
