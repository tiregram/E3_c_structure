
#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "../TP3/liste.h"
#include "../TP3/debug.h"


T_arbre* cree_arbre()
  {
    T_arbre* ret = malloc(sizeof(T_arbre) * 1);
    ret->left = NULL;
    ret->right = NULL;

    return ret;
  }

int est_vide_arbre(T_arbre* a)
{
  if( a == NULL)
    return 1;

  return 0;
}

void insere_arbre(T_arbre*a, void *pc, int (*compare)(void *, void *))
{
  printf("insert\n");
  T_arbre*new = cree_arbre();
  new->data =pc;
  accroche_gauche(a,new);

}

void libere_arbre(T_arbre*a, void(* lib_contenu)(void *))
{
  libere_arbre(arbre_gauche(a),lib_contenu);
  libere_arbre(arbre_droite(a),lib_contenu);

  lib_contenu(a->data);
  free(a);
}


void affiche_arbre_rec(T_arbre*a, void(* aff_contenu)(void *),int deca)
{
  if(arbre_have_gauche(a))
    {
      printf("%*c",deca,' ');
      printf("↳");
      affiche_arbre_rec(arbre_gauche(a),aff_contenu,deca);
    }


  aff_contenu(a);

  if(arbre_have_droite(a)){
    printf("%*c",deca,' ');
    printf("↱");
    affiche_arbre_rec(arbre_droite(a),aff_contenu,deca);
  }

}


void affiche_arbre(T_arbre*a, void(* aff_contenu)(void *))
{
  affiche_arbre_rec(a,aff_contenu,0);
}


void accroche_gauche(T_arbre*a, T_arbre*fg)
{
  a->left = fg;
}

void accroche_droite(T_arbre*a, T_arbre*fd)
{
  a->right = fd;
}

T_arbre* arbre_gauche(T_arbre*a)
{
  return a->left;
}

T_arbre* arbre_droite(T_arbre*a)
{
  return a->right;
}


int  arbre_have_droite(T_arbre*  a)
{
  return arbre_droite(a) != NULL ;
}

int  arbre_have_gauche(T_arbre*  a)
{
  return arbre_gauche(a) != NULL ;
}

void *contenu_arbre(T_arbre* pa)
{
  return pa->data;
}
