//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/1/2018.
//

#ifndef VIRTUAL_MACHINE_DIVFUNCTOR_H
#define VIRTUAL_MACHINE_DIVFUNCTOR_H

#include <Cpu/CpuState.h>
#include <iostream>
#include <limits>
#include "InstructionFunctor.h"

namespace cpu {
    class DivFunctor : public InstructionFunctor {
    private:
        cpu::CpuState *cpuState;
    public:
        DivFunctor(cpu::CpuState *state);

        virtual void operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                uint8_t register1, uint8_t register2, uint32_t literal);

        void div(uint8_t dataSize, uint8_t register1, uint8_t register2);

        template<typename T>
        void executeDiv(uint8_t register1, uint8_t register2);
    };
}

template<typename T>
void cpu::DivFunctor::executeDiv(uint8_t register1, uint8_t register2) {
    uint64_t flag = 0;
    std::cout << flag << std::endl;

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
    std::cout << flag << std::endl;
    cpuState->setFlags(flag);
    cpuState->writeToDataRegisters(register1, val);
}

#endif //VIRTUAL_MACHINE_DIVFUNCTOR_H
