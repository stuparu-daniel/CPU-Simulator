cmake_minimum_required(VERSION 3.16)

set (unit-tests LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)

file(GLOB SRC_FILES "*.test.cpp")
foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(EXEC_NAME ${SRC_FILE} NAME_WLE)
    add_executable(${EXEC_NAME} ${SRC_FILE})
    set_target_properties(shared PROPERTIES LINKER_LANGUAGE CXX)
    target_link_libraries (${EXEC_NAME} PUBLIC SystemC::systemc)
    target_link_libraries (${EXEC_NAME} PRIVATE shared)
endforeach()
