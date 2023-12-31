cmake_minimum_required(VERSION 3.16)
project(cpu-simulator LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 17)

# TODO: Fix multiple driver issue in cpu-simulator example.
# TODO: Fix segfault when cpu-simulator is not started from the current directory.
add_executable (cpu-simulator main.cpp
                         modules/bios/bios.h
                         modules/bios/bios.cpp
                         modules/paging/paging.h
                         modules/paging/paging.cpp
                         modules/icache/icache.h
                         modules/icache/icache.cpp
                         modules/fetch/fetch.h
                         modules/fetch/fetch.cpp
                         modules/decode/decode.h
                         modules/decode/decode.cpp
                         modules/exec/exec.h
                         modules/exec/exec.cpp
                         modules/mmxu/mmxu.h
                         modules/mmxu/mmxu.cpp
                         modules/floating/floating.h
                         modules/floating/floating.cpp
                         modules/dcache/dcache.h
                         modules/dcache/dcache.cpp
                         modules/pic/pic.h
                         modules/pic/pic.cpp
                         modules/rng/rng.h
                         modules/rng/rng.cpp
                         modules/stimulus/stimulus.h
                         modules/stimulus/stimulus.cpp
                         )

include_directories(modules
                    modules/bios
                    modules/dcache
                    modules/decode
                    modules/exec
                    modules/fetch
                    modules/floating
                    modules/icache
                    modules/mmxu
                    modules/paging
                    modules/pic
                    modules/rng
                    modules/stimulus
                    shared
                    )


add_subdirectory(libs/systemc-2.3.3)
add_subdirectory(libs/Catch2)
add_subdirectory(shared)
add_subdirectory(unit-tests)
set_target_properties(shared PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries (cpu-simulator PUBLIC SystemC::systemc)
target_link_libraries (cpu-simulator PUBLIC Catch2)
target_link_libraries (cpu-simulator PRIVATE shared)

# set (cpu-simulator_EXTRAS
#                       abc.asm
#                       assembler.pl
#                       bios.img
#                       dcache.img
#                       icache.img
#                       printout.img
#                       program.img
#                       register.img
#                       test.asm
#                       test1.asm)


# foreach (cpu-simulator_EXTRAS ${cpu-simulator_EXTRA})
#   configure_file (${CMAKE_SOURCE_DIR}/src/${cpu-simulator_EXTRA} ${CMAKE_CURRENT_BINARY_DIR}/${cpu-simulator_EXTRA} COPYONLY)
# endforeach (cpu-simulator_EXTRAS ${cpu-simulator_EXTRA})
