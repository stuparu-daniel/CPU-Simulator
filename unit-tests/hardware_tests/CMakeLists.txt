cmake_minimum_required(VERSION 3.16)
# project(shared C CXX)

set (hardware_tests LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)

find_package(SystemCLanguage CONFIG REQUIRED)

foreach (hardware_test IN LISTS hardware_tests)
  add_executable(dbg_pair_${hardware_test}.test pair/${hardware_test}.test.cpp)
  target_link_libraries(dbg_pair_${hardware_test} PRIVATE hardware_test::hardware_test)
  set_property(
    TARGET dbg_pair_${hardware_test}
    PROPERTY RUNTIME_OUTPUT_DIRECTORY 
             "${CMAKE_CURRENT_BINARY_DIR}/dbg_pair_${hardware_test}"
  )
endforeach ()

# find_package(Catch2 CONFIG REQUIRED)

# target_link_libraries (shared PUBLIC SystemC::systemc)

# add_library (unit-tests directive.h 
#                     module_testing.h
# )

