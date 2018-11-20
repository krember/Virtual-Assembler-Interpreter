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
    void loadFile(StructuredFile& file); // TODO: use Loader
    uint8_t getByte(uint32_t address);
    uint16_t getWord(uint32_t address);
    uint32_t getDWord(uint32_t address);
    uint64_t getQWord(uint32_t address); // TODO: single interface
};


#endif //VIRTUAL_MACHINE_MEMORY_H
