#include <CUnit/Basic.h>

#include "test/test_list.h"

int init_test(void) {return 0;}
int clean_test(void){return 0;}

int main(void)
{
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();


  pSuite = CU_add_suite("list", init_test, clean_test);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */
  /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
  if ((NULL == CU_add_test(pSuite, "data test", test_list_data   )) ||
      (NULL == CU_add_test(pSuite, "list test", test_list_maillon)) ||
      (NULL == CU_add_test(pSuite, "list test", test_list_list   ))
      )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();

}
