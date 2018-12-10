//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_BINARYREGISTERWISEFUNCTOR_H
#define VIRTUAL_MACHINE_BINARYREGISTERWISEFUNCTOR_H

#include <Cpu/CpuState.h>
#include <cstdint>
#include "InstructionFunctor.h"

namespace cpu {
    class BinaryRegisterwiseFunctor : public InstructionFunctor {
    public:
        explicit BinaryRegisterwiseFunctor(cpu::CpuState *state);

        virtual void operator()(Instruction & instruction);

        virtual void execute(uint8_t dataSize, uint8_t register1, uint8_t register2) = 0;
    };
}

#endif //VIRTUAL_MACHINE_BINARYREGISTERWISEFUNCTOR_H
