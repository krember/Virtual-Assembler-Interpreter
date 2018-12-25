//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_STOREFUNCTOR_H
#define VIRTUAL_MACHINE_STOREFUNCTOR_H

#include <VM/Memory.h>
#include "InstructionFunctor.h"
#include "Cpu/CpuState.h"

namespace cpu {
    class StoreFunctor : public InstructionFunctor {
    private:
        vm::Memory* vMemory;

    public:
        explicit StoreFunctor(cpu::CpuState *state, vm::Memory * _memory);

        virtual void operator()(Instruction & instruction);

        virtual void execute(uint8_t dataSize, uint8_t reg, uint8_t address);

        template<typename T>
        void executeOp(uint8_t reg, uint8_t address);
    };
}

template<typename T>
void cpu::StoreFunctor::executeOp(uint8_t reg, uint8_t addressReg) {
    vMemory->write<T>(cpuState->readFromAddressRegister(addressReg), cpuState->readFromDataRegister<T>(reg));
}


#endif //VIRTUAL_MACHINE_STOREFUNCTOR_H
