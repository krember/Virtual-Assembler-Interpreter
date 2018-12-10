//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_SUBFUNCTOR_H
#define VIRTUAL_MACHINE_SUBFUNCTOR_H

#include "Cpu/Functors/InstructionFunctor.h"
#include "Config/CPUConstants.h"
#include "Cpu/CPU.h"
#include "BinaryRegisterwiseFunctor.h"
#include <stdio.h>
#include <iostream>

namespace cpu {
    class SubFunctor : public BinaryRegisterwiseFunctor {
    public:
        explicit SubFunctor(cpu::CpuState *state);

        virtual void execute(uint8_t dataSize, uint8_t register1, uint8_t register2);

        template<typename T>
        void executeOp(uint8_t register1, uint8_t register2);
    };
}

template<typename T>
void cpu::SubFunctor::executeOp(uint8_t register1, uint8_t register2) {
    uint64_t flag = 0;

    T val = cpuState->readFromDataRegister<T>(register1) - cpuState->readFromDataRegister<T>(register2);
    __asm ("pushf    \n\t"
           "pop %[flag]"
           :[flag] "=&r"(flag));

    cpuState->setFlags(flag);
    cpuState->writeToDataRegisters(register1, val);
}

#endif //VIRTUAL_MACHINE_SUBFUNCTOR_H
