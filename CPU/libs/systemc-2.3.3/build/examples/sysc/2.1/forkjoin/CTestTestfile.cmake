# CMake generated Testfile for 
# Source directory: /home/adrian/systemc/systemc-2.3.3/examples/sysc/2.1/forkjoin
# Build directory: /home/adrian/systemc/systemc-2.3.3/build/examples/sysc/2.1/forkjoin
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(examples/sysc/2.1/forkjoin/forkjoin "/usr/bin/cmake" "-DTEST_EXE=/home/adrian/systemc/systemc-2.3.3/build/examples/sysc/2.1/forkjoin/forkjoin" "-DTEST_DIR=/home/adrian/systemc/systemc-2.3.3/build/examples/sysc/2.1/forkjoin" "-DTEST_INPUT=" "-DTEST_GOLDEN=/home/adrian/systemc/systemc-2.3.3/examples/sysc/2.1/forkjoin/golden.log" "-DTEST_FILTER=" "-DDIFF_COMMAND=/usr/bin/diff" "-DDIFF_OPTIONS=-u" "-P" "/home/adrian/systemc/systemc-2.3.3/cmake/run_test.cmake")
set_tests_properties(examples/sysc/2.1/forkjoin/forkjoin PROPERTIES  FAIL_REGULAR_EXPRESSION "^[*][*][*]ERROR" _BACKTRACE_TRIPLES "/home/adrian/systemc/systemc-2.3.3/examples/CMakeLists.txt;137;add_test;/home/adrian/systemc/systemc-2.3.3/examples/sysc/2.1/forkjoin/CMakeLists.txt;44;configure_and_add_test;/home/adrian/systemc/systemc-2.3.3/examples/sysc/2.1/forkjoin/CMakeLists.txt;0;")
