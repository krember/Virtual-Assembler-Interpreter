//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Functors/PopSfFunctor.h"

cpu::PopSfFunctor::PopSfFunctor(cpu::CpuState *_cpuState, InstructionFunctor * _pushFunctor) : InstructionFunctor(_cpuState) {
    PopFunctor * _push = dynamic_cast<PopFunctor*>(_pushFunctor);
    if(_push == nullptr) {
        throw ExecutionException("Cannot initialize call instruction without push instruction");
    }
    pushFunctor = _push;
}

void cpu::PopSfFunctor::operator()(cpu::Instruction &instruction) {
    pushFunctor->executeOp<uint32_t>(cpuState->generalPurposeRegisters.size() + 2);
    cpuState->sf = cpuState->sp;
}
