//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_BREAKFUNCTOR_H
#define VIRTUAL_MACHINE_BREAKFUNCTOR_H

#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"

namespace cpu {
    class BreakFunctor : public InstructionFunctor {
    public:
        BreakFunctor(cpu::CpuState*state);

        virtual void operator()(Instruction & instruction);
    };
}



#endif //VIRTUAL_MACHINE_BREAKFUNCTOR_H
