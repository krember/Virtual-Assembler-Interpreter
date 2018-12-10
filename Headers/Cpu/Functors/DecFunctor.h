//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/3/2018.
//

#ifndef VIRTUAL_MACHINE_DECFUNCTOR_H
#define VIRTUAL_MACHINE_DECFUNCTOR_H

#include <cstdint>
#include <iostream>
#include "Cpu/CPU.h"

namespace cpu {
    class DecFunctor : public InstructionFunctor {
    public:
        DecFunctor(cpu::CpuState *state);

        virtual void operator()(Instruction & instruction);

        void execute(uint8_t dataSize, uint8_t register1);

        template<typename T>
        void executeOp(uint8_t register1);
    };
}

template<typename T>
void cpu::DecFunctor::executeOp(uint8_t register1) {
    uint64_t flag = 0;

    T val = cpuState->readFromDataRegister<T>(register1) - 1;
    __asm ("pushf    \n\t"
           "pop %[flag]"
    :[flag] "=&r"(flag));

    cpuState->setFlags(flag);
    cpuState->writeToDataRegisters(register1, val);
}

#endif //VIRTUAL_MACHINE_DECFUNCTOR_H
