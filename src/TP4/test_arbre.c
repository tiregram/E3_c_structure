
#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "../TP3/contenu.h"
#include "../TP3/liste.h"
#include "../TP3/util.h"
#include "../TP3/debug.h"

void test_arbre() {

  char rep[8];
  contenu *pc;
  T_arbre *pa;

  pa=cree_arbre();
  
  for(;;) {

    printf("\n\
1. (I)nsere arbre\n                             \
\n                                              \
0. (F)inir\n                                    \
Choix : ");
    saisie_chaine(rep,2);

    switch(rep[0]) {

    case 'I': case'i': case'1':
      
      insere_arbre(pa,pc = cree_alea_contenu(0),
                   (int(*)(void *, void *))compare_contenu);

      printf("%-20s : ","Ajout : \n");
      affiche_contenu(pc);
      printf("\n");

      printf("%-10s : \n", "Arbree");

      affiche_arbre(pa,(void(*)(void *))affiche_contenu);
      printf("\n");
      break;
    case'F': case'f': case'0':

      libere_arbre(pa,(void(*)(void *))libere_contenu);
      mon_free(pa);

      printf("Fin\n");

      return ;
    }
  }
}


int main(int argc, char *argv[])
{
  test_arbre();
  return 0;
}

