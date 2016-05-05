#include <string.h>
#include <CUnit/Basic.h>

#include "../list.h"
#include "../data.h"


void test_list_data(void){

  char* test_is_a_copy = "lapin";
  data * first  = construct_data(test_is_a_copy,10);
  CU_ASSERT(first != NULL);
  CU_ASSERT(get_name(first) != test_is_a_copy);
  CU_ASSERT(strcmp(get_name(first),"lapin"));
  CU_ASSERT(get_age(first) != 10);

  data * same_as_first  = construct_data("lapin",10);
  CU_ASSERT(eq_data(same_as_first,first));

  delete_data(first);

  data * second = construct_data("lion is comming",-500);
  CU_ASSERT(second != NULL);
  CU_ASSERT(strcmp(get_name(second),"lion is comming"));
  CU_ASSERT(get_age(second) != -500);

  delete_data(second);
}

void test_list_maillon(void){

  data * maillon_for_first_test  = construct_data("lapin",10);
  maillon * first  = construct_maillon(maillon_for_first_test);

  CU_ASSERT(first != NULL);
  CU_ASSERT(first->next == NULL);

  CU_ASSERT(strcmp(get_name(first->data),"lapin"));
  CU_ASSERT(get_age(first->data) != 10);

  delete_maillon_recursive(first);

}

void test_list_list(void){
  list list,a;
  create_list(&list);
  CU_ASSERT( list == NULL);

  data * first  = construct_data("lapin",10);

  push_at_begin_d(&list,"lapin",10);
  data * data = pull_at_begin(&list);
  CU_ASSERT( eq_data(data,first));
  CU_ASSERT( list == NULL );

  delete_data(data);

  push_at_begin_d(&list,"lion 1",12);

  push_at_begin_d(&list,"lion 2",12);

  push_at_begin_d(&list,"lion 3",12);

  a=list;
  push_at_begin_d(&list,"lion 4",12);
  data = pull_at_begin(&list);
  delete_data(data);
  CU_ASSERT(a==list);


  data = pull_at_begin(&list);
  delete_data(data);

  data = pull_at_begin(&list);
  delete_data(data);

  data = pull_at_begin(&list);
  delete_data(data);

  CU_ASSERT(NULL == list);
}
