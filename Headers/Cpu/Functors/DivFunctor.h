//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/1/2018.
//

#ifndef VIRTUAL_MACHINE_DIVFUNCTOR_H
#define VIRTUAL_MACHINE_DIVFUNCTOR_H

#include <Cpu/CpuState.h>
#include <iostream>
#include <limits>
#include "InstructionFunctor.h"
#include "BinaryRegisterwiseFunctor.h"

namespace cpu {
    class DivFunctor : public BinaryRegisterwiseFunctor {
    public:
        explicit DivFunctor(cpu::CpuState *state);

        virtual void execute(uint8_t dataSize, uint8_t register1, uint8_t register2);

        template<typename T>
        void executeOp(uint8_t register1, uint8_t register2);
    };
}

template<typename T>
void cpu::DivFunctor::executeOp(uint8_t register1, uint8_t register2) {
    uint64_t flag = 0;

    T secondArgument = cpuState->readFromDataRegister<T>(register2);
    T val;
    if(secondArgument == 0) {
        val = std::numeric_limits<T>::infinity();
    } else {
        val = cpuState->readFromDataRegister<T>(register1) / secondArgument;
    }
    __asm ("pushf    \n\t"
           "pop %[flag]"
    :[flag] "=&r"(flag));

    cpuState->setFlags(flag);
    cpuState->writeToDataRegisters(register1, val);
}

#endif //VIRTUAL_MACHINE_DIVFUNCTOR_H
