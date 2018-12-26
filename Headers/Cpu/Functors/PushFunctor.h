//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_PUSHFUNCTOR_H
#define VIRTUAL_MACHINE_PUSHFUNCTOR_H

#include "Cpu/CpuState.h"
#include <VM/Memory.h>
#include <Exceptions/ExecutionException.h>
#include <Config/VMConstants.h>
#include "InstructionFunctor.h"

namespace cpu {
    class PushFunctor : public InstructionFunctor {
    private:
        vm::Memory* vMemory;
    public:
        PushFunctor(CpuState *state, vm::Memory* memory);

        virtual void operator()(Instruction & instruction);

        void execute(uint8_t dataSize, uint8_t register1);

        template<typename T>
        void executeOp(uint8_t _register);
    };
}

template<typename T>
void cpu::PushFunctor::executeOp(uint8_t _register) {
    cpuState->sp -= sizeof(T);
    if (vMemory->getMemorySize() - cpuState->sp > vMemory->getStackSize()) {
        throw ExecutionException("Stack overflow");
    }
    if(_register >= cpuState->generalPurposeRegisters.size()) {
        vMemory->write(cpuState->sp, cpuState->readFromDataRegister<uint32_t>(_register));
    } else {
        vMemory->write(cpuState->sp, cpuState->readFromDataRegister<T>(_register) );
    }
}

#endif //VIRTUAL_MACHINE_PUSHFUNCTOR_H
