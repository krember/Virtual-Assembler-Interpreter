//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_OPCODEPARSER_H
#define VIRTUAL_MACHINE_OPCODEPARSER_H

#include "Config/LanguageConstants.h"
#include <cstdint>

class Instruction {
private:
    static const uint8_t REGISTERS_ORDER_MASK = 0b00000011;
    static const uint8_t JUMP_EXTENSION_MASK =  0b00111100;
    static const uint8_t DATA_SIZE_MASK = 0b11000000;

    /* Private members */
    uint8_t opCode;
    uint8_t jumpExtension;
    uint8_t dataSize;
    uint8_t registersOrder;
    uint8_t register1;
    uint8_t register2;
    uint32_t literal;

public:
    /* Constructing */
    Instruction(uint64_t instructionCode);

    /* Public interface */
    uint8_t getOpCode();

    uint8_t getJumpExtension() const;

    uint8_t getDataSize() const;

    uint8_t getRegistersOrder() const;

    uint8_t getRegister1() const;

    uint8_t getRegister2() const;

    uint32_t getLiteral() const;
};


#endif //VIRTUAL_MACHINE_OPCODEPARSER_H
