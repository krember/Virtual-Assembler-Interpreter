//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include "../Headers/Memory.h"

void Memory::loadFile(StructuredFile &file) {

}

uint8_t Memory::getByte(uint32_t address) {
    return data.at(address);
}

uint16_t Memory::getWord(uint32_t address) {
    return *reinterpret_cast<uint16_t *>(data.data() + address);
}

uint32_t Memory::getDWord(uint32_t address) {
    return *reinterpret_cast<uint32_t *>(data.data() + address);
}

uint64_t Memory::getQWord(uint32_t address) {
    return *reinterpret_cast<uint64_t *>(data.data() + address);
}
