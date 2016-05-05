#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "data.h"
#include "maillon.h"

#include "list.h"


void create_list(list* list_to_init)
{
  // check
  assert(list_to_init == NULL);

  *list_to_init = NULL;
}

void push_at_begin(list * list,maillon* maillon_to_add)
{
  // check
  assert(list != NULL);
  assert(maillon_to_add != NULL);

  // ancien => suivant du nouveau
  maillon_to_add->next = *list;
  // nouveaux = first element de la list
  *list = maillon_to_add;

  return;
}

void push_at_begin_d(list * list, char * name, int age)
{
  maillon * maillon_to_add = construct_maillon_d(name,age);
  push_at_begin(list,maillon_to_add);

  return;
}

int list_is_empty(list* list_empty_or_not)
{
  // check
  assert(list_empty_or_not != NULL);

  return (*list_empty_or_not) == NULL;
}

data* pull_at_begin(list * list)
{
  //check
  assert(list != NULL);
  maillon * old_maillon = *list;

  // si la liste est vide alors on retourne null
  if(list_is_empty(list))
    return NULL;

  data * ret_data = old_maillon->data;


  // maillon suivant = new
  *list = (old_maillon)->next;

  // free the maillon
  delete_maillon(old_maillon);

  return ret_data;
}


void print_list(list*list_to_print)
{
  //check
  assert(list_to_print == NULL);
  printf("list([");

  for(maillon * one_maillon = *list_to_print;
      one_maillon != NULL;
      one_maillon = one_maillon->next)
    {
      print_maillon(one_maillon);
    }

  printf("])");

  return;
}

void delete_list(list * list_to_free)
{
  //check
  assert(list_to_free == NULL);

  maillon * free_maillon = *list_to_free;
  maillon * next = NULL;
  while(free_maillon != NULL)
    {
      next = free_maillon->next;
      delete_maillon_recursive(free_maillon);
      free_maillon = next;
    }
}
