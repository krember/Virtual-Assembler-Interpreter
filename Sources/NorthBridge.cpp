//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include <NorthBridge.h>

#include "../Headers/NorthBridge.h"

NorthBridge::NorthBridge(Memory *memory) : vMemory(memory) {
}

uint32_t NorthBridge::readFromMemory(uint32_t address) {
    return vMemory->read<uint32_t >(address);
}

uint64_t NorthBridge::readInstructionFromMemory(uint32_t address) {
    return vMemory->read<uint64_t>(address);
}
