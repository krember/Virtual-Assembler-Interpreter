//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/3/2018.
//

#include "Cpu/Functors/DecFunctor.h"
#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>

cpu::DecFunctor::DecFunctor(cpu::CpuState *_cpuState) : InstructionFunctor(_cpuState) {}

void cpu::DecFunctor::operator()(Instruction & instruction) {
    switch (instruction.getRegistersOrder()) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RR:
            execute(instruction.getDataSize(), instruction.getRegister1());
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + std::to_string(instruction.getRegistersOrder()));
    }
}

void cpu::DecFunctor::execute(uint8_t dataSize, uint8_t register1) {
    switch (dataSize) {
        case DataSize::B:
            executeOp<uint8_t>(register1);
            break;
        case DataSize::W:
            executeOp<uint16_t>(register1);
            break;
        case DataSize::DW:
            executeOp<uint32_t>(register1);
            break;
        case DataSize::QW:
            executeOp<uint64_t>(register1);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + std::to_string(dataSize));
    }
}

