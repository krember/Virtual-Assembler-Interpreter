//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_PUSHSFFUNCTOR_H
#define VIRTUAL_MACHINE_PUSHSFFUNCTOR_H


#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"
#include "PushFunctor.h"

namespace cpu {
    class PushSfFunctor : public InstructionFunctor {
    public:
        PushSfFunctor(cpu::CpuState *state, InstructionFunctor * _pushFunctor);

        virtual void operator()(Instruction & instruction);
    private:
        PushFunctor * pushFunctor;
    };
}

#endif //VIRTUAL_MACHINE_PUSHSFFUNCTOR_H
