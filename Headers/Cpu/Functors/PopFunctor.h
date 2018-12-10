//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_POPFUNCTOR_H
#define VIRTUAL_MACHINE_POPFUNCTOR_H

#include <Exceptions/ExecutionException.h>
#include <VM/Memory.h>
#include <cstdint>
#include "InstructionFunctor.h"
#include "Cpu/CpuState.h"

namespace cpu {
    class PopFunctor : public InstructionFunctor {
    private:
        vm::Memory* vMemory;
    public:
        PopFunctor(CpuState *state, vm::Memory* memory);

        virtual void operator()(Instruction & instruction);

        void execute(uint8_t dataSize, uint8_t register1);

        template<typename T>
        void executeOp(uint8_t _register);
    };
}

template<typename T>
void cpu::PopFunctor::executeOp(uint8_t _register) {
    T val = vMemory->read<T>(cpuState->sp);
    cpuState->writeToDataRegisters(_register, val);
    cpuState->sp += sizeof(T);
}


#endif //VIRTUAL_MACHINE_POPFUNCTOR_H
