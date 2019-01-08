//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_POPSFFUNCTOR_H
#define VIRTUAL_MACHINE_POPSFFUNCTOR_H

#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"
#include "PopFunctor.h"

namespace cpu {
    class PopSfFunctor : public InstructionFunctor {
    public:
        PopSfFunctor(cpu::CpuState *state, InstructionFunctor * _pushFunctor);

        virtual void operator()(Instruction & instruction);
    private:
        PopFunctor * pushFunctor;
    };
}

#endif //VIRTUAL_MACHINE_POPSFFUNCTOR_H
