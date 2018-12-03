//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_SUMFUNCTOR_H
#define VIRTUAL_MACHINE_SUMFUNCTOR_H

#include <cstdint>
#include <iostream>
#include "Cpu/CPU.h"
#include "BinaryRegisterwiseFunctor.h"

namespace cpu {
    class SumFunctor : public BinaryRegisterwiseFunctor {
    public:
        explicit SumFunctor(cpu::CpuState *state);

        virtual void execute(uint8_t dataSize, uint8_t register1, uint8_t register2);

        template<typename T>
        void executeOp(uint8_t register1, uint8_t register2);
    };
}

template<typename T>
void cpu::SumFunctor::executeOp(uint8_t register1, uint8_t register2) {
    uint16_t flag = 0;

    T val = cpuState->readFromDataRegister<T>(register1) + cpuState->readFromDataRegister<T>(register2);
    __asm ("pushf    \n\t"
           "pop %[flag]"
           :[flag] "=&r"(flag));

    cpuState->setFlags(flag);
    cpuState->writeToDataRegisters(register1, val);
}


#endif //VIRTUAL_MACHINE_SUMFUNCTOR_H

