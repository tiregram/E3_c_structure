/* liste.c */

#include <stdio.h>
#include <stdlib.h>

#include "debug.h"

#include "liste.h"

typedef struct maillon {
    void * contenu;
    struct maillon *svt;
} maillon;

/* cuisine interne. N'est jamais vu de l'exterieur */

static maillon *cree_maillon(void *pc, maillon *svt) {
    maillon *pm = (maillon*)mon_malloc(sizeof(maillon));
    pm->contenu = pc;
    pm->svt = svt;
    return pm;
}

static void libere_maillon(maillon *pm, void(* lib_contenu)(void *)) {
    void * pc = pm->contenu;
    mon_free(pm);
    if (lib_contenu!=NULL) {
        lib_contenu(pc);
    }
}

liste *cree_liste() {
    liste *l=(liste *)mon_malloc(sizeof(liste));
    *l = NULL;
    return l;
}

int est_vide_liste(liste *l) {
    return *l==NULL;
}

void libere_liste(liste *l, void(* lib_contenu)(void *)) {

    maillon *pm = (maillon*)*l, *qm ;
    while (pm != NULL) {
        qm = pm->svt;
        libere_maillon(pm,lib_contenu);
        pm = qm;
    }
    mon_free(l);

}


void ajoute_en_tete_liste(liste *l, void *pc) {
    maillon *pm = cree_maillon(pc, (maillon*) *l);
    *l = pm;
}

void *tete_de_liste(liste *l) {
    if (! est_vide_liste(l)) {
        return ((maillon *)*l)->contenu;
    }
    else {
        return NULL;
    }
}

void *retire_en_tete_liste(liste *l) {
    if (! est_vide_liste(l)) {
        maillon *pm = (maillon*)*l;
        void *pc = pm->contenu;
        *l = pm -> svt;
        libere_maillon(pm, NULL);
        return pc;
    }
    else {
        return NULL;
    }
}

void affiche_liste(liste *l, void (*aff)(void *)) {
    maillon *pm = (maillon*)*l;
    while (pm!=NULL) {
        aff(pm->contenu);
        pm = pm->svt;
    }
}

void insere_liste (liste *l, void *pc, int (*compare)(void *, void *)) {
  if (est_vide_liste(l) || compare(pc, tete_de_liste(l))<=0 ) {
        ajoute_en_tete_liste(l, pc);
    }
    else {
        insere_liste((liste *)&(((maillon *)*l)->svt), pc, compare);
    }
}


void tri_liste(liste *l, int (*compare)(void *, void *)) {
	void *pc;

  if (est_vide_liste(l) )
    return;

  tri_liste((liste *)&(((maillon *)*l)->svt), compare);

  pc = retire_en_tete_liste(l);
  insere_liste(l, pc,compare);
}

void insere_liste_static (liste *l, void *pc, int (*compare)(void *, void *))
{
  if (est_vide_liste(l) || compare(pc, tete_de_liste(l))<=0 )
    {
      ((maillon*)pc)->svt = (maillon*)*l;
      *l = (liste)pc;
    }
  else
    {
      liste newSuite = (liste)(((maillon*)l)->svt);
      insere_liste_static(&newSuite, (maillon*) pc, compare);
      ((maillon *)(*l))->svt = (maillon *)newSuite;
    }
}

void tri_liste_static(liste *l, int (*compare)(void *, void *))
{

  if (est_vide_liste(l))
    return;

  liste newSuite = (liste)((maillon*)l)->svt;

  tri_liste_static(&newSuite, compare);
  insere_liste_static(&newSuite,(maillon*)*l,compare);
  *l = newSuite;
}

pile * cree_pile() {
    return cree_liste();
}

void* retire_pile(pile *p) {
    return retire_en_tete_liste(p);
}
void ajoute_pile (pile *p, void *c) {
    ajoute_en_tete_liste(p, c);
}

void libere_pile(liste *l, void(* lib_contenu)(void *)){
    libere_liste(l, lib_contenu);
}

void * sommet_pile(pile *p) {
    return tete_de_liste(p);
}

void affiche_pile(pile *p, void (* aff)(void *)) {
    affiche_liste((liste *)p, aff);
}

