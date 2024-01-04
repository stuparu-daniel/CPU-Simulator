cmake_minimum_required(VERSION 3.16)
project(cpu-simulator)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs/systemc-2.3.3)


# TODO: Fix multiple driver issue in cpu-simulator example.
# TODO: Fix segfault when cpu-simulator is not started from the current directory.
add_executable (cpu-simulator main.cpp
                         modules/directive.h
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
                         modules/pic/pic.cpp)
target_link_libraries (cpu-simulator PUBLIC SystemC::systemc)

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
                    modules/pic)

set (cpu-simulator_EXTRAS
                      abc.asm
                      assembler.pl
                      bios.img
                      dcache.img
                      icache.img
                      printout.img
                      program.img
                      register.img
                      test.asm
                      test1.asm)

foreach (cpu-simulator_EXTRA ${risc_cpu_EXTRAS})
  configure_file (${CMAKE_CURRENT_SOURCE_DIR}/${cpu-simulator_EXTRA} ${CMAKE_CURRENT_BINARY_DIR}/${cpu-simulator_EXTRA} COPYONLY)
endforeach (cpu-simulator_EXTRA ${risc_cpu_EXTRAS})
