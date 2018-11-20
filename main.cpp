#include <iostream>
#include "Headers/VirtualMachine.h"

int main() {

    std::vector<uint8_t> ram;
    ram.push_back(0);
    ram.push_back(0);
    ram.push_back(02342);
    ram.push_back(102);
    ram.push_back(1);
    ram.push_back(123);
    ram.push_back(133);
    ram.push_back(0);
    ram.push_back(14);
    ram.push_back(0);
    ram.push_back(0);
    ram.push_back(1);

    uint32_t *value = reinterpret_cast<uint32_t *>(ram.data() + 5);

    std::cout << *value << std::endl;

    std::cout<< (int)ram.at(5) <<std::endl;
    *value = 1;
    std::cout<< (int)ram.at(5) <<std::endl;

    std::cout << *value;
    return 0;
}