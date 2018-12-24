//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_RETFUNCTOR_H
#define VIRTUAL_MACHINE_RETFUNCTOR_H

#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"
#include "PopFunctor.h"

namespace cpu {
    class RetFunctor : public InstructionFunctor {
    public:
        RetFunctor(cpu::CpuState *state, InstructionFunctor * _pushFunctor);

        virtual void operator()(Instruction & instruction);

        void execute(uint8_t dataSize);

        void executeOp();
    private:
        PopFunctor* popFunctor;
    };
}

#endif //VIRTUAL_MACHINE_RETFUNCTOR_H
