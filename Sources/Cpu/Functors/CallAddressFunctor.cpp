//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Functors/CallAddressFunctor.h"
#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>

cpu::CallAddressFunctor::CallAddressFunctor(cpu::CpuState *_cpuState, InstructionFunctor * _pushFunctor) : InstructionFunctor(_cpuState) {
    PushFunctor * _push = dynamic_cast<PushFunctor*>(_pushFunctor);
    if(_push == nullptr) {
        throw ExecutionException("Cannot initialize call instruction without push instruction");
    }
    pushFunctor = _push;
}

void cpu::CallAddressFunctor::operator()(Instruction & instruction) {
    switch (instruction.getRegistersOrder()) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
        case RegisterOrder::RR:
            execute(instruction.getDataSize(), instruction.getLiteral());
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + std::to_string(instruction.getRegistersOrder()));
    }
}

void cpu::CallAddressFunctor::execute(uint8_t dataSize,uint32_t literal) {
    switch (dataSize) {
        case DataSize::B:
        case DataSize::W:
        case DataSize::DW:
        case DataSize::QW:
            executeOp(literal);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + std::to_string(dataSize));
    }
}

void cpu::CallAddressFunctor::executeOp(uint32_t literal) {
    pushFunctor->executeOp<uint32_t>(cpuState->generalPurposeRegisters.size());
    cpuState->ip = literal + 8;
}