//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_NORTHBRIDGE_H
#define VIRTUAL_MACHINE_NORTHBRIDGE_H


#include "Memory.h"

class NorthBridge {
private:
    /* Private members */
    Memory * vMemory;
public:
    /* Constructing */
    NorthBridge(Memory * memory);

    /* Public interface */
    uint64_t readInstructionFromMemory(uint32_t address);
    uint32_t readFromMemory(uint32_t address);
};


#endif //VIRTUAL_MACHINE_NORTHBRIDGE_H
