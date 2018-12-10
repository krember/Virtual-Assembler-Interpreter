//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include <vector>
#include "Cpu/Instruction.h"

cpu::Instruction::Instruction() {
}

void cpu::Instruction::init(uint64_t instructionCode) {
    uint8_t * bytes = reinterpret_cast<uint8_t *>(&instructionCode);

    opCode = bytes[0];
    dataSize = (bytes[1] & DATA_SIZE_MASK) >> 6;
    jumpExtension = (bytes[1] & JUMP_EXTENSION_MASK) >> 2;
    registersOrder = bytes[1] & REGISTERS_ORDER_MASK;
    register1 = bytes[2];
    register2 = bytes[3];
    literal = *(reinterpret_cast<uint32_t *>(bytes + 4));
}

uint8_t cpu::Instruction::getOpCode() {
    return opCode;
}

uint8_t cpu::Instruction::getJumpExtension() const {
    return jumpExtension;
}

uint8_t cpu::Instruction::getDataSize() const {
    return dataSize;
}

uint8_t cpu::Instruction::getRegistersOrder() const {
    return registersOrder;
}

uint8_t cpu::Instruction::getRegister1() const {
    return register1;
}

uint8_t cpu::Instruction::getRegister2() const {
    return register2;
}

uint32_t cpu::Instruction::getLiteral() const {
    return literal;
}
