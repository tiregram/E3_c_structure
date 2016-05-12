#include "fifo.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

fifo* creer_fifo()
{
  fifo * a = malloc(sizeof(fifo));
  a->first = NULL;
  a->last = NULL;

  return a;
}

int est_vide_file(fifo *f)
{
  return f->first == NULL;
}

int defiler_file(fifo* f,contenu * cont)
{
  assert(!est_vide_file(f));

  struct elem*el = f->first;

  contenu* conte = el->data;
  affecte_contenu(cont,conte);

  if(f->first == f->last)
    {
      f->first  = NULL;
      f->last = NULL;
    }
  else
    {
      f->first = el->prev;
    }


  free(conte);
  free(el);

  return 0;
}

int enfiler_file(fifo* f,contenu * cont)
{
  struct elem* elem = malloc(sizeof(struct elem));
  contenu* conte = malloc(sizeof(contenu));
  affecte_contenu(conte,cont);
  elem->data = conte;
  elem->prev = NULL;

  f->last->prev = elem;
  f-> last = elem;

  if(f->first== NULL)
    f->first = f->last;

  return 0;

}


void afficher_file(fifo * f)
{
  for(struct elem* i = f->first; i!= NULL;i = i->prev)
    {
      print_contenu(i->data);
      printf("<");
    }
  return;
}

void delete_file(fifo *f)
{
  contenu a;

  while(!est_vide_file(f))
    defiler_file(f,&a);

  free(f);

  return;
}
