/* liste.h */

#ifndef LISTE_H
#define LISTE_H

typedef void * liste;

liste* cree_liste();
void libere_liste(liste *l, void(* libere_contenu)(void *));
int est_vide_liste(liste *l);

void ajoute_en_tete_liste(liste *l, void *pc);
void *retire_en_tete_liste(liste *l);
void *tete_de_liste(liste *l);
void affiche_liste(liste *l, void (*aff)(void *)) ;
void insere_liste (liste *l, void *pc, int (*compare)(void *, void *)) ;
void tri_liste(liste *l, int (*compare)(void *, void *));


typedef liste pile;

pile * cree_pile() ;
void* retire_pile(pile *p) ;
void ajoute_pile (pile *p, void *c) ;
void libere_pile(liste *l, void(* lib_contenu)(void *)) ;
void * sommet_pile(pile *p) ;
void affiche_pile(pile *p, void (* aff)(void *)) ;


#endif



