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
        CallAddressFunctor(cpu::CpuState *state);

        virtual void operator()(Instruction & instruction);

        void execute(uint8_t dataSize, uint8_t register1);

        template<typename T>
        void executeOp(uint8_t register1);
    private:
        PushFunctor pushFunctor;
    };
}

template<typename T>
void cpu::CallAddressFunctor::executeOp(uint8_t register1) {
   //TODO TO Do
}

#endif //VIRTUAL_MACHINE_CALLADDRESSFUNCTOR_H
