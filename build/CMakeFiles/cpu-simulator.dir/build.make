# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/solo/Proiect_FIC/CPU-Simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/solo/Proiect_FIC/CPU-Simulator/build

# Include any dependencies generated for this target.
include CMakeFiles/cpu-simulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpu-simulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpu-simulator.dir/flags.make

CMakeFiles/cpu-simulator.dir/main.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpu-simulator.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/main.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/main.cpp

CMakeFiles/cpu-simulator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/main.cpp > CMakeFiles/cpu-simulator.dir/main.cpp.i

CMakeFiles/cpu-simulator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/main.cpp -o CMakeFiles/cpu-simulator.dir/main.cpp.s

CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.o: ../modules/bios/bios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/bios/bios.cpp

CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/bios/bios.cpp > CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.i

CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/bios/bios.cpp -o CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.s

CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.o: ../modules/paging/paging.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/paging/paging.cpp

CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/paging/paging.cpp > CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.i

CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/paging/paging.cpp -o CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.s

CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.o: ../modules/icache/icache.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/icache/icache.cpp

CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/icache/icache.cpp > CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.i

CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/icache/icache.cpp -o CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.s

CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.o: ../modules/fetch/fetch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/fetch/fetch.cpp

CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/fetch/fetch.cpp > CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.i

CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/fetch/fetch.cpp -o CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.s

CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.o: ../modules/decode/decode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/decode/decode.cpp

CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/decode/decode.cpp > CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.i

CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/decode/decode.cpp -o CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.s

CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.o: ../modules/exec/exec.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/exec/exec.cpp

CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/exec/exec.cpp > CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.i

CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/exec/exec.cpp -o CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.s

CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.o: ../modules/mmxu/mmxu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/mmxu/mmxu.cpp

CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/mmxu/mmxu.cpp > CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.i

CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/mmxu/mmxu.cpp -o CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.s

CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.o: ../modules/floating/floating.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/floating/floating.cpp

CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/floating/floating.cpp > CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.i

CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/floating/floating.cpp -o CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.s

CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.o: ../modules/dcache/dcache.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/dcache/dcache.cpp

CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/dcache/dcache.cpp > CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.i

CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/dcache/dcache.cpp -o CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.s

CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.o: ../modules/pic/pic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/pic/pic.cpp

CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/pic/pic.cpp > CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.i

CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/pic/pic.cpp -o CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.s

CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.o: ../modules/rng/rng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/rng/rng.cpp

CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/rng/rng.cpp > CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.i

CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/rng/rng.cpp -o CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.s

CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.o: ../modules/stimulus/stimulus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/modules/stimulus/stimulus.cpp

CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/modules/stimulus/stimulus.cpp > CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.i

CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/modules/stimulus/stimulus.cpp -o CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.s

CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.o: CMakeFiles/cpu-simulator.dir/flags.make
CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.o: ../unit-tests/hardware_tests/module_testing_example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.o -c /home/solo/Proiect_FIC/CPU-Simulator/unit-tests/hardware_tests/module_testing_example.cpp

CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solo/Proiect_FIC/CPU-Simulator/unit-tests/hardware_tests/module_testing_example.cpp > CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.i

CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solo/Proiect_FIC/CPU-Simulator/unit-tests/hardware_tests/module_testing_example.cpp -o CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.s

# Object files for target cpu-simulator
cpu__simulator_OBJECTS = \
"CMakeFiles/cpu-simulator.dir/main.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.o" \
"CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.o" \
"CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.o"

# External object files for target cpu-simulator
cpu__simulator_EXTERNAL_OBJECTS =

cpu-simulator: CMakeFiles/cpu-simulator.dir/main.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/bios/bios.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/paging/paging.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/icache/icache.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/fetch/fetch.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/decode/decode.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/exec/exec.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/mmxu/mmxu.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/floating/floating.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/dcache/dcache.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/pic/pic.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/rng/rng.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/modules/stimulus/stimulus.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/unit-tests/hardware_tests/module_testing_example.cpp.o
cpu-simulator: CMakeFiles/cpu-simulator.dir/build.make
cpu-simulator: libs/systemc-2.3.3/src/libsystemc.so.2.3.3
cpu-simulator: shared/libshared.so
cpu-simulator: CMakeFiles/cpu-simulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable cpu-simulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpu-simulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpu-simulator.dir/build: cpu-simulator

.PHONY : CMakeFiles/cpu-simulator.dir/build

CMakeFiles/cpu-simulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpu-simulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpu-simulator.dir/clean

CMakeFiles/cpu-simulator.dir/depend:
	cd /home/solo/Proiect_FIC/CPU-Simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/solo/Proiect_FIC/CPU-Simulator /home/solo/Proiect_FIC/CPU-Simulator /home/solo/Proiect_FIC/CPU-Simulator/build /home/solo/Proiect_FIC/CPU-Simulator/build /home/solo/Proiect_FIC/CPU-Simulator/build/CMakeFiles/cpu-simulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpu-simulator.dir/depend

