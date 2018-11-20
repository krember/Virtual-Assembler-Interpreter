//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/15/18.
//

#include "../Headers/BinaryUtils.h"

std::vector<uint8_t> BinaryUtils::split(uint8_t value) {
    const int count = 1;
    std::vector<uint8_t > bytes(count);
    for (int i = 0; i < count; ++i)
        bytes[count - 1 - i] = (value >> (i * 8));

    return bytes;
}

std::vector<uint8_t> BinaryUtils::split(uint16_t value) {
    const int count = 2;
    std::vector<uint8_t > bytes(count);
    for (int i = 0; i < count; ++i)
        bytes[count - 1 - i] = (value >> (i * 8));

    return bytes;
}

std::vector<uint8_t> BinaryUtils::split(uint32_t value) {
    const int count = 4;
    std::vector<uint8_t > bytes(count);
    for (int i = 0; i < count; ++i)
        bytes[count - 1 - i] = (value >> (i * 8));

    return bytes;
}

std::vector<uint8_t> BinaryUtils::split(uint64_t value) {
    const int count = 8;
    std::vector<uint8_t > bytes(count);
    for (int i = 0; i < count; ++i)
        bytes[count - 1 - i] = (value >> (i * 8));

    return bytes;
}

uint16_t BinaryUtils::join2(std::vector<uint8_t> bytes) {
    uint16_t value = bytes[0] << 8 + bytes[1];
    return value;
}

uint32_t BinaryUtils::join4(std::vector<uint8_t> bytes) {
    uint16_t value = bytes[0] << 8 + bytes[1];
    for(int i = 2; i < 4; ++i) {
        value = value << 8 + bytes[i];
    }
    return value;
}

uint64_t BinaryUtils::join8(std::vector<uint8_t> bytes) {
    uint16_t value = bytes[0] << 8 + bytes[1];
    for(int i = 2; i < 8; ++i) {
        value = value << 8 + bytes[i];
    }
    return value;
}
