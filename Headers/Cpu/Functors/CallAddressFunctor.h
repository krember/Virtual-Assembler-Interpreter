//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_CALLADDRESSFUNCTOR_H
#define VIRTUAL_MACHINE_CALLADDRESSFUNCTOR_H

#include <cstdint>
#include <iostream>
#include "Cpu/CPU.h"
#include "PushFunctor.h"

namespace cpu {
    class CallAddressFunctor : public InstructionFunctor {
    public:
        CallAddressFunctor(cpu::CpuState *state, InstructionFunctor * _pushFunctor);

        virtual void operator()(Instruction & instruction);

        void execute(uint8_t dataSize, uint32_t literal);

        void executeOp(uint32_t literal);
    private:
        PushFunctor* pushFunctor;
    };
}

#endif //VIRTUAL_MACHINE_CALLADDRESSFUNCTOR_H
