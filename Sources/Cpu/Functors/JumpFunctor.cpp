//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/3/2018.
//

#include "Cpu/Functors/JumpFunctor.h"
#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>

cpu::JumpFunctor::JumpFunctor(cpu::CpuState *_cpuState) : InstructionFunctor(_cpuState) {}

void cpu::JumpFunctor::operator()(Instruction & instruction) {
    switch (instruction.getRegistersOrder()) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
        case RegisterOrder::RR:
            execute(instruction.getDataSize(), instruction.getJumpExtension(), instruction.getLiteral());
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + std::to_string(instruction.getRegistersOrder()));
    }
}

void cpu::JumpFunctor::execute(uint8_t dataSize, uint8_t jumpExtension,uint32_t literal) {
    switch (dataSize) {
        case DataSize::B:
            executeOp<uint8_t>(jumpExtension, literal);
            break;
        case DataSize::W:
            executeOp<uint16_t>(jumpExtension, literal);
            break;
        case DataSize::DW:
            executeOp<uint32_t>(jumpExtension, literal);
            break;
        case DataSize::QW:
            executeOp<uint64_t>(jumpExtension, literal);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + std::to_string(dataSize));
    }
}

