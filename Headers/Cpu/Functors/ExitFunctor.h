//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_EXITFUNCTOR_H
#define VIRTUAL_MACHINE_EXITFUNCTOR_H


#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"
#include "PopFunctor.h"

namespace cpu {
    class ExitFunctor : public InstructionFunctor {
    public:
        ExitFunctor(cpu::CpuState *state);

        virtual void operator()(Instruction & instruction);

        void execute(uint8_t dataSize);

        void executeOp();
    };
}


#endif //VIRTUAL_MACHINE_EXITFUNCTOR_H
