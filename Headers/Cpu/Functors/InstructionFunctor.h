//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_INSTRUCTIONFUNCTOR_H
#define VIRTUAL_MACHINE_INSTRUCTIONFUNCTOR_H

#include <cstdint>

namespace cpu {
    class InstructionFunctor {
    public:
        virtual void operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                uint8_t register1, uint8_t register2, uint32_t literal) = 0;
    };
}

#endif //VIRTUAL_MACHINE_INSTRUCTIONFUNCTOR_H
