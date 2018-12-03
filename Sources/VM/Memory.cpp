//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <VM/Memory.h>

vm::Memory::Memory(size_t memorySize, size_t stackSize) : data(memorySize,0) {
}