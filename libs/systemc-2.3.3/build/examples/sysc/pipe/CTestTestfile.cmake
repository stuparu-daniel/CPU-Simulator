# CMake generated Testfile for 
# Source directory: /home/adrian/systemc/systemc-2.3.3/examples/sysc/pipe
# Build directory: /home/adrian/systemc/systemc-2.3.3/build/examples/sysc/pipe
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(examples/sysc/pipe/pipe "/usr/bin/cmake" "-DTEST_EXE=/home/adrian/systemc/systemc-2.3.3/build/examples/sysc/pipe/pipe" "-DTEST_DIR=/home/adrian/systemc/systemc-2.3.3/build/examples/sysc/pipe" "-DTEST_INPUT=" "-DTEST_GOLDEN=" "-DTEST_FILTER=" "-DDIFF_COMMAND=/usr/bin/diff" "-DDIFF_OPTIONS=-u" "-P" "/home/adrian/systemc/systemc-2.3.3/cmake/run_test.cmake")
set_tests_properties(examples/sysc/pipe/pipe PROPERTIES  FAIL_REGULAR_EXPRESSION "^[*][*][*]ERROR" _BACKTRACE_TRIPLES "/home/adrian/systemc/systemc-2.3.3/examples/CMakeLists.txt;137;add_test;/home/adrian/systemc/systemc-2.3.3/examples/sysc/pipe/CMakeLists.txt;54;configure_and_add_test;/home/adrian/systemc/systemc-2.3.3/examples/sysc/pipe/CMakeLists.txt;0;")
