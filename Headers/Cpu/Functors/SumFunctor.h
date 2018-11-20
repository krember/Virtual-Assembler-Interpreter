//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_SUMFUNCTOR_H
#define VIRTUAL_MACHINE_SUMFUNCTOR_H

#include <cstdint>
#include "Cpu/CPU.h"


namespace cpu {
    class SumFunctor : public InstructionFunctor {
    private:
        cpu::CPU* cpu;
    public:
        SumFunctor(cpu::CPU* _cpu);

        void operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                        uint8_t register1, uint8_t register2, uint32_t literal);
        void sum(uint8_t dataSize, uint8_t register1, uint8_t register2);
    };
}

#endif //VIRTUAL_MACHINE_SUMFUNCTOR_H
