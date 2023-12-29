#include "modules/cpu/cpu.h"
#include <iostream>
#include <systemc.h>

int sc_main(int argc, char* argv[]) {

    sc_start();

    return 0;
}

// int main() {
//     std::shared_ptr<Flags> flags = std::make_shared<Flags>();
//     CPU cpu(flags);
//     std::ifstream file("assembly.txt");
//     cpu.fetch(file);
//     cpu.execute();
//     return 0;
// }
