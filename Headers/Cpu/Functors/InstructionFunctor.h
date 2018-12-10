//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_INSTRUCTIONFUNCTOR_H
#define VIRTUAL_MACHINE_INSTRUCTIONFUNCTOR_H

#include <cstdint>
#include <Cpu/Instruction.h>

namespace cpu {
struct CpuState;
}

namespace cpu {
    class InstructionFunctor {
    protected:
        cpu::CpuState *cpuState;

    public:
        explicit InstructionFunctor(cpu::CpuState * _state);

        virtual void operator()(Instruction & instruction) = 0;
    };
}

#endif //VIRTUAL_MACHINE_INSTRUCTIONFUNCTOR_H
