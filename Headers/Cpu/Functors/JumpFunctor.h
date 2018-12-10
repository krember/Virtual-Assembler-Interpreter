//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/3/2018.
//

#ifndef VIRTUAL_MACHINE_JUMPFUNCTOR_H
#define VIRTUAL_MACHINE_JUMPFUNCTOR_H

#include <cstdint>
#include <iostream>
#include <Config/CPUConstants.h>
#include "Cpu/CPU.h"

namespace cpu {
    class JumpFunctor : public InstructionFunctor {
    public:
        JumpFunctor(cpu::CpuState *state);

        virtual void operator()(Instruction & instruction);

        void execute(uint8_t dataSize, uint8_t jumpExtension, uint32_t literal);

        template<typename T>
        void executeOp(uint8_t jumpExtension, uint32_t literal);
    };
}

template<typename T>
void cpu::JumpFunctor::executeOp(uint8_t jumpExtension, uint32_t literal) {
    if (cpuState->getFlags().checkCondition(JumpCondition(jumpExtension))) {
        cpuState->ip = literal;
    }
}

#endif //VIRTUAL_MACHINE_JUMPFUNCTOR_H
