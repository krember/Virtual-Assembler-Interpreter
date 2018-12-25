//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>
#include "Cpu/Functors/LoadFunctor.h"


cpu::LoadFunctor::LoadFunctor(cpu::CpuState *state, vm::Memory * _memory) : InstructionFunctor(state), vMemory(_memory) {

}

void cpu::LoadFunctor::operator()(Instruction & instruction) {
    switch (instruction.getRegistersOrder()) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RR:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RA:
            execute(instruction.getDataSize(), instruction.getRegister1(), instruction.getRegister2());
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + std::to_string(instruction.getRegistersOrder()));
    }
}

void cpu::LoadFunctor::execute(uint8_t dataSize, uint8_t reg, uint8_t address) {
    switch (dataSize) {
        case DataSize::B:
            executeOp<uint8_t>(reg, address);
            break;
        case DataSize::W:
            executeOp<uint16_t>(reg, address);
            break;
        case DataSize::DW:
            executeOp<uint32_t>(reg, address);
            break;
        case DataSize::QW:
            executeOp<uint64_t>(reg, address);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + std::to_string(dataSize));
    }
}
