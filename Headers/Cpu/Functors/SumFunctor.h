//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_SUMFUNCTOR_H
#define VIRTUAL_MACHINE_SUMFUNCTOR_H

#include <cstdint>
#include <iostream>
#include "Cpu/CPU.h"

namespace cpu {
    class SumFunctor : public InstructionFunctor {
    private:
        cpu::CpuState *cpuState;
    public:
        SumFunctor(cpu::CpuState *state);

        virtual void operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                uint8_t register1, uint8_t register2, uint32_t literal);

        void sum(uint8_t dataSize, uint8_t register1, uint8_t register2);

        template<typename T>
        void executeSum(uint8_t register1, uint8_t register2);
    };
}

template<typename T>
void cpu::SumFunctor::executeSum(uint8_t register1, uint8_t register2) {
    register uint64_t flag asm("rax") = 0;
    std::cout<<flag<<std::endl;
    T val = cpuState->getRegister<T>(register1) + cpuState->getRegister<T>(register2);
    __asm ("pushf    \n\t"
           "pop %[flag]"
    :[flag] "=&r"(flag));
    std::cout<<flag<<std::endl;
}


#endif //VIRTUAL_MACHINE_SUMFUNCTOR_H

