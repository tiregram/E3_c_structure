#include "contenu.h"

#ifndef G__FIFO
#define G__FIFO

struct elem
{
  void * data;
  struct elem* prev;
};


typedef struct fifo
{
  struct elem* first;
  struct elem* last;
} fifo;


fifo* creer_fifo();

int est_vide_file(fifo* f);

int defiler_file(fifo* f,contenu * cont);

int enfiler_file(fifo* f,contenu * cont);

void afficher_file(fifo *f);

void delete_file(fifo* f);
#endif
