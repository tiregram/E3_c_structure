cmake_minimum_required (VERSION 2.6)

project (StructureDeDonne)

##################################################################
#TP1
##################################################################

# factoriel
file(GLOB_RECURSE
     source_files_TP1_fact
     src/TP1/factoriel.c
     )
add_executable(./bin/TP1/TP1_fact  ${source_files_TP1_fact})

enable_testing()

# stack list
file(GLOB_RECURSE
  source_files_TP1_list
  src/TP1/list/*.c
  )
add_executable(./bin/TP1/TP1_list_test  ${source_files_TP1_list})
set_target_properties(./bin/TP1/TP1_list_test PROPERTIES LINK_FLAGS -Wl,-lcunit)

add_test (test_lib test_lib)
