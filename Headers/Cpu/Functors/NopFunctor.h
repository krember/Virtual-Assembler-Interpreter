//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_NOP_H
#define VIRTUAL_MACHINE_NOP_H


#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"

namespace cpu {
    class NopFunctor : public InstructionFunctor {
    public:
        NopFunctor(cpu::CpuState*state);

        virtual void operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                uint8_t register1, uint8_t register2, uint32_t literal);
    };
}


#endif //VIRTUAL_MACHINE_NOP_H
