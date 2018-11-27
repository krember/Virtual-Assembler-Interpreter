//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_SUMFUNCTOR_H
#define VIRTUAL_MACHINE_SUMFUNCTOR_H

#include <cstdint>
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
    uint64_t register flag asm("rax") = 0;
    T val = cpuState->getRegister<T>(register1) + cpuState->getRegister<T>(register2);
    __asm ( "pushf    \n\t"
            "pop %rax \n\t");
    cpuState->writeToRegisters(register1, val);
}


#endif //VIRTUAL_MACHINE_SUMFUNCTOR_H

