<<<<<<< Updated upstream
# Install script for directory: /home/dani/fic/CPU-Simulator
=======
# Install script for directory: /home/solo/Proiect_FIC/CPU-Simulator
>>>>>>> Stashed changes

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/opt/systemc")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
<<<<<<< Updated upstream
  include("/home/dani/fic/CPU-Simulator/build/libs/systemc-2.3.3/cmake_install.cmake")
=======
  include("/home/solo/Proiect_FIC/CPU-Simulator/build/libs/systemc-2.3.3/cmake_install.cmake")
>>>>>>> Stashed changes
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
<<<<<<< Updated upstream
  include("/home/dani/fic/CPU-Simulator/build/libs/Catch2/cmake_install.cmake")
=======
  include("/home/solo/Proiect_FIC/CPU-Simulator/build/libs/Catch2/cmake_install.cmake")
>>>>>>> Stashed changes
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
<<<<<<< Updated upstream
  include("/home/dani/fic/CPU-Simulator/build/shared/cmake_install.cmake")
=======
  include("/home/solo/Proiect_FIC/CPU-Simulator/build/shared/cmake_install.cmake")
>>>>>>> Stashed changes
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
<<<<<<< Updated upstream
  include("/home/dani/fic/CPU-Simulator/build/unit-tests/cmake_install.cmake")
=======
  include("/home/solo/Proiect_FIC/CPU-Simulator/build/unit-tests/cmake_install.cmake")
>>>>>>> Stashed changes
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< Updated upstream
file(WRITE "/home/dani/fic/CPU-Simulator/build/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/home/solo/Proiect_FIC/CPU-Simulator/build/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> Stashed changes
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
