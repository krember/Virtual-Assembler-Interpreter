//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Functors/RetFunctor.h"

cpu::RetFunctor::RetFunctor(cpu::CpuState *state, cpu::InstructionFunctor *_popFunctor) : InstructionFunctor(state) {
    PopFunctor * _pop = dynamic_cast<PopFunctor*>(_popFunctor);
    if(_pop == nullptr) {
        throw ExecutionException("Cannot initialize ret instruction without pop instruction");
    }
    popFunctor = _pop;
}

void cpu::RetFunctor::operator()(cpu::Instruction &instruction) {
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

void cpu::RetFunctor::execute(uint8_t dataSize) {
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

void cpu::RetFunctor::executeOp() {
    popFunctor->executeOp<uint32_t>(cpuState->generalPurposeRegisters.size());
}
