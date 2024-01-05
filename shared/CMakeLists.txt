cmake_minimum_required(VERSION 3.16)
# project(shared C CXX)

set (shared LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)

find_package(SystemCLanguage CONFIG REQUIRED)


# find_package(Catch2 CONFIG REQUIRED)

# target_link_libraries (shared PUBLIC SystemC::systemc)

add_library (shared directive.h 
                    module_testing.h
)
