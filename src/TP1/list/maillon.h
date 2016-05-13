#include "data.h"

#ifndef G__MAILLON__
#define G__MAILLON__


typedef struct maillon
{
  void* data;
  struct maillon *next;
} maillon;

typedef maillon *list;

maillon * construct_maillon(void* data_to_the_maillon,int size_of_data);
maillon * construct_maillon_d(char * name,int age);

void print_maillon(maillon* maillon_to_print);

void delete_maillon_recursive(maillon* maillon_to_free);
void delete_maillon(maillon* maillon_to_free);

#endif
