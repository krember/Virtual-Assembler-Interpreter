//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_MEMORY_H
#define VIRTUAL_MACHINE_MEMORY_H

#include "StructuredFile.h"

class Memory {
private:
    std::vector<uint8_t> data;
public:
    template <typename valueType>
    valueType read(uint32_t address);

    template <typename valueType>
    void write(uint8_t address, valueType data);
};

template<typename valueType>
uint8_t Memory::read(uint32_t address) {
    return *reinterpret_cast<valueType *>(data.data() + address);
}

template<typename valueType>
void Memory::write(uint8_t address, valueType data) {
    *reinterpret_cast<valueType *>(data.data() + address) = data;
}

#endif //VIRTUAL_MACHINE_MEMORY_H
