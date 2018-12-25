//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_LOADFUNCTOR_H
#define VIRTUAL_MACHINE_LOADFUNCTOR_H

#include <VM/Memory.h>
#include "InstructionFunctor.h"
#include "Cpu/CpuState.h"

namespace cpu {
    class LoadFunctor : public InstructionFunctor {
    private:
        vm::Memory* vMemory;

    public:
        explicit LoadFunctor(cpu::CpuState *state, vm::Memory * _memory);

        virtual void operator()(Instruction & instruction);

        virtual void execute(uint8_t dataSize, uint8_t reg, uint8_t address);

        template<typename T>
        void executeOp(uint8_t reg, uint8_t address);
    };
}

template<typename T>
void cpu::LoadFunctor::executeOp(uint8_t reg, uint8_t address) {
    cpuState->writeToDataRegisters<T>(reg, vMemory->read<T>(cpuState->readFromAddressRegister(address)));
}

#endif //VIRTUAL_MACHINE_LOADFUNCTOR_H
