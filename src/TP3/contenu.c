/* contenu.c */


#include <stdio.h> /* pour printf */
#include <time.h>
#include <string.h> /* pour strlen strcmp et strcpy */
#include <stdlib.h> /* pour rand */


#include "contenu.h"
#include "debug.h"
#include "util.h"

contenu * cree_contenu(char *nom,unsigned int birth,unsigned int died ) {
  contenu *pc = (contenu*)mon_malloc(sizeof(contenu));
  pc->nom = (char *)mon_malloc(strlen(nom)+1);
  strcpy(pc->nom, nom);
  pc->birth = birth;
  pc->died = died;

  return pc;
}

#define N 10
contenu * cree_alea_contenu() {
  char nom[N+1]="rabit";
  int birth,died;
  
  birth = rand()%900 +1000;
  died  = birth + rand()%110;

  return cree_contenu(nom, birth,died);
}


void affiche_contenu(contenu *pc){
  
  printf("%-*s (%4d)  (%4d)",N,pc->nom, pc->birth,pc->died);
}

void libere_contenu(contenu *pc) {
  mon_free(pc->nom);
  mon_free(pc);
}

int compare_contenu(contenu *pc1, contenu* pc2) {
  int c = strcmp(pc1->nom,pc2->nom);

  if(c != 0)
    {
      return c;
    }

  if(pc1->birth != pc2->birth )
    {
      return pc1->birth < pc2->birth ;
    }

  if(pc1->died != pc2->died )
    {
      return pc1->died < pc2->died ;
    }

  return 0;

}

int compare_valeur(contenu *pc1, contenu* pc2) {
  int c = strcmp(pc1->nom,pc2->nom);

  if(pc1->birth != pc2->birth )
    {
      return pc1->birth < pc2->birth ;
    }

  if(pc1->died != pc2->died )
    {
      return pc1->died < pc2->died ;
    }

  if(c!=0)
    {
      return c;
    }

  return 0;

}


