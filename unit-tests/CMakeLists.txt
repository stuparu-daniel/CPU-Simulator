cmake_minimum_required(VERSION 3.16)

set (unit-tests LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)

find_package(SystemCLanguage CONFIG REQUIRED)

add_subdirectory(software_tests)
add_subdirectory(hardware_tests)
