# CMake generated Testfile for 
# Source directory: /home/adrian/systemc/systemc-2.3.3/examples/sysc/fir
# Build directory: /home/adrian/systemc/systemc-2.3.3/build/examples/sysc/fir
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(examples/sysc/fir/fir "/usr/bin/cmake" "-DTEST_EXE=/home/adrian/systemc/systemc-2.3.3/build/examples/sysc/fir/fir" "-DTEST_DIR=/home/adrian/systemc/systemc-2.3.3/build/examples/sysc/fir" "-DTEST_INPUT=" "-DTEST_GOLDEN=" "-DTEST_FILTER=" "-DDIFF_COMMAND=/usr/bin/diff" "-DDIFF_OPTIONS=-u" "-P" "/home/adrian/systemc/systemc-2.3.3/cmake/run_test.cmake")
set_tests_properties(examples/sysc/fir/fir PROPERTIES  FAIL_REGULAR_EXPRESSION "^[*][*][*]ERROR" _BACKTRACE_TRIPLES "/home/adrian/systemc/systemc-2.3.3/examples/CMakeLists.txt;137;add_test;/home/adrian/systemc/systemc-2.3.3/examples/sysc/fir/CMakeLists.txt;51;configure_and_add_test;/home/adrian/systemc/systemc-2.3.3/examples/sysc/fir/CMakeLists.txt;0;")
add_test(examples/sysc/fir/fir_rtl "/usr/bin/cmake" "-DTEST_EXE=/home/adrian/systemc/systemc-2.3.3/build/examples/sysc/fir/fir_rtl" "-DTEST_DIR=/home/adrian/systemc/systemc-2.3.3/build/examples/sysc/fir" "-DTEST_INPUT=" "-DTEST_GOLDEN=" "-DTEST_FILTER=" "-DDIFF_COMMAND=/usr/bin/diff" "-DDIFF_OPTIONS=-u" "-P" "/home/adrian/systemc/systemc-2.3.3/cmake/run_test.cmake")
set_tests_properties(examples/sysc/fir/fir_rtl PROPERTIES  FAIL_REGULAR_EXPRESSION "^[*][*][*]ERROR" _BACKTRACE_TRIPLES "/home/adrian/systemc/systemc-2.3.3/examples/CMakeLists.txt;137;add_test;/home/adrian/systemc/systemc-2.3.3/examples/sysc/fir/CMakeLists.txt;65;configure_and_add_test;/home/adrian/systemc/systemc-2.3.3/examples/sysc/fir/CMakeLists.txt;0;")
