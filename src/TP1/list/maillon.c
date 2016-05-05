#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "data.h"

#include "maillon.h"

maillon * construct_maillon(data* data_to_the_maillon)
{
  // check
  assert(data_to_the_maillon == NULL);

  // malloc the maillon
  maillon * new_maillon = malloc(sizeof(maillon) * 1);
  assert(new_maillon == NULL);

  // remplir
  new_maillon->next = NULL;
  new_maillon->data = data_to_the_maillon;

  return new_maillon;
}

maillon* construct_maillon_d(char * name,int age)
{
  data* data = construct_data(name,age);
  return  construct_maillon(data);
}

void delete_maillon(maillon* maillon_to_free)
{
  //check
  assert(maillon_to_free != NULL);

  free(maillon_to_free);
  return;
}

void delete_maillon_recursive(maillon* maillon_to_free)
{
  //check
  assert(maillon_to_free != NULL);

  //free content and itself
  delete_data(maillon_to_free->data);
  delete_maillon(maillon_to_free);
  return;
}

void print_maillon(maillon * maillon_to_print)
{
  printf("maillon(data=");
  print_data(maillon_to_print->data);
  printf(")");

}



