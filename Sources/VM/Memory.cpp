//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <VM/Memory.h>

vm::Memory::Memory(size_t _memorySize, size_t _stackSize) : data(_memorySize,0), memorySize(_memorySize), stackSize(_stackSize) {
}

size_t vm::Memory::getMemorySize() const {
    return memorySize;
}

size_t vm::Memory::getStackSize() const {
    return stackSize;
}
