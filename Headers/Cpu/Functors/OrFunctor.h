//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_ORFUNCTOR_H
#define VIRTUAL_MACHINE_ORFUNCTOR_H


#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"
#include "BinaryRegisterwiseFunctor.h"

namespace cpu {
    class OrFunctor : public BinaryRegisterwiseFunctor {
    public:
        explicit OrFunctor(cpu::CpuState *state);

        virtual void execute(uint8_t dataSize, uint8_t register1, uint8_t register2);

        template<typename T>
        void executeOp(uint8_t register1, uint8_t register2);
    };
}

template<typename T>
void cpu::OrFunctor::executeOp(uint8_t register1, uint8_t register2) {
    uint64_t flag = 0;

    T val = cpuState->readFromDataRegister<T>(register1) | cpuState->readFromDataRegister<T>(register2);
    __asm ("pushf    \n\t"
           "pop %[flag]"
            :[flag] "=&r"(flag));

    cpuState->setFlags(flag);
    cpuState->writeToDataRegisters(register1, val);
}


#endif //VIRTUAL_MACHINE_ORFUNCTOR_H
