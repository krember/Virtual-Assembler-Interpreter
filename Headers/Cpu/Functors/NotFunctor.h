//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_NOTFUNCTOR_H
#define VIRTUAL_MACHINE_NOTFUNCTOR_H


#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"

namespace cpu {
    class NotFunctor : public InstructionFunctor {
    public:
        NotFunctor(CpuState *state);

        virtual void operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                uint8_t register1, uint8_t register2, uint32_t literal);

        void execute(uint8_t dataSize, uint8_t register1);

        template<typename T>
        void executeOp(uint8_t _register);
    };
}

template<typename T>
void cpu::NotFunctor::executeOp(uint8_t _register) {
    uint16_t flag = 0;

    T val = cpuState->readFromDataRegister<T>(_register) + 1;
    __asm ("pushf    \n\t"
           "pop %[flag]"
    :[flag] "=&r"(flag));

    cpuState->setFlags(flag);
    cpuState->writeToDataRegisters(_register, val);
}


#endif //VIRTUAL_MACHINE_NOTFUNCTOR_H
