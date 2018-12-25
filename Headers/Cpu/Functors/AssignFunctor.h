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

        virtual void operator()(Instruction &instruction);

        void execute(uint8_t dataSize, uint8_t register1, uint32_t literal, bool isData);

        template<typename T>
        void executeOp(uint8_t register1, uint32_t literal, bool isData);
    };
}

template<typename T>
void cpu::AssignFunctor::executeOp(uint8_t register1, uint32_t literal, bool isData) {
    if (isData) {
        cpuState->writeToDataRegisters(register1, T(literal));
    } else {
        cpuState->writeToAddressRegisters(register1,literal);
    }
}


#endif //VIRTUAL_MACHINE_ASSIGNFUNCTOR_H
