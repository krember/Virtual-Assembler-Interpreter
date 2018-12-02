//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/3/2018.
//

#ifndef VIRTUAL_MACHINE_JUMPFUNCTOR_H
#define VIRTUAL_MACHINE_JUMPFUNCTOR_H

#include <cstdint>
#include <iostream>
#include "Cpu/CPU.h"

namespace cpu {
    class JumpFunctor : public InstructionFunctor {
    private:
        cpu::CpuState *cpuState;
    public:
        JumpFunctor(cpu::CpuState *state);

        virtual void operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                uint8_t register1, uint8_t register2, uint32_t literal);

        void jump(uint8_t dataSize, uint32_t literal);

        template<typename T>
        void executeJump(uint32_t literal);
    };
}

template<typename T>
void cpu::JumpFunctor::executeJump(uint32_t literal) {
    uint64_t flag = 0;

    cpuState->ip = literal;
    __asm ("pushf    \n\t"
           "pop %[flag]"
    :[flag] "=&r"(flag));

    cpuState->setFlags(flag);
}

#endif //VIRTUAL_MACHINE_JUMPFUNCTOR_H
