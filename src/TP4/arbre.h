#ifndef H_STRUCTURE_DATA
#define H_STRUCTURE_DATA

//typedef struct STRUCT_tree arbre;


typedef struct struct_tree {
  void * data;
  struct struct_tree * left;
  struct struct_tree * right;
} T_arbre;



T_arbre* cree_arbre();
int est_vide_arbre(T_arbre*a);
void insere_arbre(T_arbre*a, void *pc, int (*compare)(void *, void *));
void libere_arbre(T_arbre*a, void(* lib_contenu)(void *)) ;
void affiche_arbre(T_arbre*a, void(* aff_contenu)(void *)) ;
void accroche_gauche(T_arbre*a, T_arbre*fg);
void accroche_droite(T_arbre*a, T_arbre*fd);
T_arbre*arbre_gauche(T_arbre*a);
T_arbre*arbre_droite(T_arbre*a);
void *contenu_arbre(T_arbre* pa);

int  arbre_have_droite(T_arbre*  a);

int  arbre_have_gauche(T_arbre*  a);

#endif
