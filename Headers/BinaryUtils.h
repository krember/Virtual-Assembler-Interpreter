//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/15/18.
//

#ifndef VIRTUAL_MACHINE_BINARYUTILS_H
#define VIRTUAL_MACHINE_BINARYUTILS_H


#include <vector>
#include <cstdint>

class BinaryUtils {
// TODO static cast
public:
    static std::vector<uint8_t> split(uint8_t value);
    static std::vector<uint8_t> split(uint16_t value);
    static std::vector<uint8_t> split(uint32_t value);
    static std::vector<uint8_t> split(uint64_t value);

    static uint16_t join2(std::vector<uint8_t> bytes) ;
    static uint32_t join4(std::vector<uint8_t> bytes) ;
    static uint64_t join8(std::vector<uint8_t> bytes) ;
};


#endif //VIRTUAL_MACHINE_BINARYUTILS_H
