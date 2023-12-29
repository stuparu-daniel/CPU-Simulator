Run these to compile & run the program (you need to be in the "/CPU" folder):

    1.This needs to be ran only once (a.k.a. not after every change made, just after you cloned the project):
      export LD_LIBRARY_PATH="./libs/systemc-2.3.3/build/src"

    2. Compile the module files:
      g++ modules/*.cpp -std=c++17 -Wall -I. -I./libs/systemc_installed/include ./libs/systemc_installed/lib-linux64/libsystemc.a -lm -o main
    
    3. (skip this for now) Compile the shared files :
      g++ shared/*.cpp -std=c++17 -Wall -I. -I./libs/systemc_installed/include ./libs/systemc_installed/lib-linux64/libsystemc.a -lm -o main

    4. (skip this for now) Compile the unit-tests files:
      g++ unit-tests/*.cpp -std=c++17 -Wall -I. -I./libs/systemc_installed/include ./libs/systemc_installed/lib-linux64/libsystemc.a -lm -o main
    
    5. Compile the main files:
      g++ *.cpp -std=c++17 -Wall -I. -I./libs/systemc_installed/include ./libs/systemc_installed/lib-linux64/libsystemc.a -lm -o main

    6. Run the program, main.cpp file:
      ./main.cpp









//ignore this: (TODO try to add this to compile command) -lsystemc