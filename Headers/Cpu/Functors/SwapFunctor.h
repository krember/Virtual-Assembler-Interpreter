//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_SWAP_H
#define VIRTUAL_MACHINE_SWAP_H

#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"
#include "BinaryRegisterwiseFunctor.h"

namespace cpu {
    class SwapFunctor : public BinaryRegisterwiseFunctor {
    public:
        explicit SwapFunctor(cpu::CpuState *state);

        virtual void execute(uint8_t dataSize, uint8_t register1, uint8_t register2);

        template<typename T>
        void executeOp(uint8_t register1, uint8_t register2);
    };
}

template<typename T>
void cpu::SwapFunctor::executeOp(uint8_t register1, uint8_t register2) {
    T valueReg1 = cpuState->readFromDataRegister<T>(register1);
    cpuState->writeToDataRegisters(register1, cpuState->readFromDataRegister<T>(register2));
    cpuState->writeToDataRegisters(register2, valueReg1);
}

#endif //VIRTUAL_MACHINE_SWAP_H
