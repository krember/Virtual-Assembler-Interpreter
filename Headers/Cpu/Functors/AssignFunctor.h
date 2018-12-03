//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/1/2018.
//

#include <Cpu/CpuState.h>
#include <iostream>
#include "InstructionFunctor.h"

#ifndef VIRTUAL_MACHINE_ASSIGNFUNCTOR_H
#define VIRTUAL_MACHINE_ASSIGNFUNCTOR_H


namespace cpu {
    class AssignFunctor : public InstructionFunctor {
    public:
        AssignFunctor(cpu::CpuState *state);

        virtual void operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                uint8_t register1, uint8_t register2, uint32_t literal);

        void execute(uint8_t dataSize, uint8_t register1, uint32_t literal);

        template<typename T>
        void executeOp(uint8_t register1, uint32_t literal);
    };
}

template<typename T>
void cpu::AssignFunctor::executeOp(uint8_t register1, uint32_t literal) {
    cpuState->writeToDataRegisters(register1, T(literal));
}



#endif //VIRTUAL_MACHINE_ASSIGNFUNCTOR_H
