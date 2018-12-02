//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/1/2018.
//

#ifndef VIRTUAL_MACHINE_MULFUNCTOR_H
#define VIRTUAL_MACHINE_MULFUNCTOR_H


#include <Cpu/CpuState.h>
#include <iostream>
#include "InstructionFunctor.h"

namespace cpu {
    class MulFunctor : public InstructionFunctor {
    private:
        cpu::CpuState *cpuState;
    public:
        MulFunctor(cpu::CpuState *state);

        virtual void operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                uint8_t register1, uint8_t register2, uint32_t literal);

        void mul(uint8_t dataSize, uint8_t register1, uint8_t register2);

        template<typename T>
        void executeMul(uint8_t register1, uint8_t register2);
    };
}

template<typename T>
void cpu::MulFunctor::executeMul(uint8_t register1, uint8_t register2) {
    uint64_t flag = 0;

    T val = cpuState->readFromDataRegister<T>(register1) * cpuState->readFromDataRegister<T>(register2);
    __asm ("pushf    \n\t"
           "pop %[flag]"
    :[flag] "=&r"(flag));

    cpuState->setFlags(flag);
    cpuState->writeToDataRegisters(register1, val);
}

#endif //VIRTUAL_MACHINE_MULFUNCTOR_H
