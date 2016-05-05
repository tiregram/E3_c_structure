#include "data.h"
#include "maillon.h"

#ifndef G__LIST__
#define G__LIST__

void create_list(list* list_to_init);

void push_at_begin(list * list,
                   maillon* maillon_to_add);

void push_at_begin_d(list * list,
                     char * name, int age);

int list_is_empty(list* list_empty_or_not);

data* pull_at_begin(list * list);

void print_list(list*list_to_print);

void delete_list(list * list_to_free);

#endif

