//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Functors/ExitFunctor.h"

cpu::ExitFunctor::ExitFunctor(cpu::CpuState *state) : InstructionFunctor(state) {}

void cpu::ExitFunctor::operator()(cpu::Instruction &instruction) {
    switch (instruction.getRegistersOrder()) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
        case RegisterOrder::RR:
            execute(instruction.getDataSize());
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + std::to_string(instruction.getRegistersOrder()));
    }
}

void cpu::ExitFunctor::execute(uint8_t dataSize) {
    switch (dataSize) {
        case DataSize::B:
        case DataSize::W:
        case DataSize::DW:
        case DataSize::QW:
            executeOp();
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + std::to_string(dataSize));
    }
}

void cpu::ExitFunctor::executeOp() {
    cpuState->bdr = cpu::HALT_EXIT_CODE;
}