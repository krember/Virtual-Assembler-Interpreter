//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/3/2018.
//

#include "Cpu/Functors/JumpFunctor.h"
#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>

cpu::JumpFunctor::JumpFunctor(cpu::CpuState *_cpuState) : InstructionFunctor(_cpuState) {}

void cpu::JumpFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder, uint8_t register1,
                                 uint8_t register2, uint32_t literal) {
    switch (registersOrder) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
        case RegisterOrder::RR:
            execute(dataSize, literal);
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + registersOrder);
    }
}

void cpu::JumpFunctor::execute(uint8_t dataSize, uint32_t literal) {
    switch (dataSize) {
        case DataSize::B:
            executeOp<uint8_t>(literal);
            break;
        case DataSize::W:
            executeOp<uint16_t>(literal);
            break;
        case DataSize::DW:
            executeOp<uint32_t>(literal);
            break;
        case DataSize::QW:
            executeOp<uint64_t>(literal);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + dataSize);
    }
}

