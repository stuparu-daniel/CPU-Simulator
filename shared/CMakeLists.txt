cmake_minimum_required(VERSION 3.16)

set (shared LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)

add_library (shared directive.h 
                    module_testing.h
)
target_link_libraries (shared PUBLIC SystemC::systemc)
