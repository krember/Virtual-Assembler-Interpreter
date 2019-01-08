//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Functors/PushSfFunctor.h"

cpu::PushSfFunctor::PushSfFunctor(cpu::CpuState *_cpuState, InstructionFunctor * _pushFunctor) : InstructionFunctor(_cpuState) {
    PushFunctor * _push = dynamic_cast<PushFunctor*>(_pushFunctor);
    if(_push == nullptr) {
        throw ExecutionException("Cannot initialize call instruction without push instruction");
    }
    pushFunctor = _push;
}

void cpu::PushSfFunctor::operator()(cpu::Instruction &instruction) {
    pushFunctor->executeOp<uint32_t>(cpuState->generalPurposeRegisters.size() + 2);
    cpuState->sf = cpuState->sp;
}
