#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "data.h"

//structure
typedef struct data
{
  char * name;
  int old;
} data;

int  get_age(data * data){return data->old;}
const char * get_name (data * data){return data->name;}


// create a data element
// name
// old
data * construct_data(const char * name, const int old)
{
  //parram check
  assert(name != NULL);

  //copy name
  char * new_name = malloc(sizeof(char)*strlen(name) + 1);
  assert(new_name != NULL);
  strcpy(new_name,name);

  // create data
  data * new_data = malloc( sizeof(data) * 1);
  assert(new_data != NULL);
  new_data->name = new_name;
  new_data->old  = old;

  return new_data;
}

void delete_data(data* data_to_free)
{
  // free sub string
  free(data_to_free->name);
  free(data_to_free);

  return;
}

void print_data(data * data)
{
  // check
  assert(data != NULL);
  assert(data->name != NULL);

  printf("data(name =%s, old = %d)",
         data->name,
         data->old
         );
}

int eq_data(const data* f, const data* s) {
  return
    (f==s) ||
    (strcmp(s->name,f->name) &&
     s->old == f->old
     );
}
