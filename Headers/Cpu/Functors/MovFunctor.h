//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_MOVFUNCTOR_H
#define VIRTUAL_MACHINE_MOVFUNCTOR_H

#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"
#include "BinaryRegisterwiseFunctor.h"

namespace cpu {
    class MovFunctor : public BinaryRegisterwiseFunctor {
    public:
        explicit MovFunctor(cpu::CpuState *state);

        virtual void execute(uint8_t dataSize, uint8_t register1, uint8_t register2);

        template<typename T>
        void executeOp(uint8_t register1, uint8_t register2);
    };
}

template<typename T>
void cpu::MovFunctor::executeOp(uint8_t register1, uint8_t register2) {
    cpuState->writeToDataRegisters(register1, cpuState->readFromDataRegister<T>(register2));
}


#endif //VIRTUAL_MACHINE_MOVFUNCTOR_H
