#include "cpu.h"
#include <iostream>

int main() {
    std::shared_ptr<Flags> flags = std::make_shared<Flags>();
    CPU cpu(flags);
    std::ifstream file("assembly.txt");
    cpu.fetch(file);
    cpu.execute();
    return 0;
}
