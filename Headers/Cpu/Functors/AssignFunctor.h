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
    private:
        cpu::CpuState *cpuState;
    public:
        AssignFunctor(cpu::CpuState *state);

        virtual void operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                uint8_t register1, uint8_t register2, uint32_t literal);

        void assign(uint8_t dataSize, uint8_t register1, uint32_t literal);

        template<typename T>
        void executeAssign(uint8_t register1, uint32_t literal);
    };
}

template<typename T>
void cpu::AssignFunctor::executeAssign(uint8_t register1, uint32_t literal) {
    uint64_t flag = 0;
    std::cout << flag << std::endl;

    T val = reinterpret_cast<T>(literal);
    __asm ("pushf    \n\t"
           "pop %[flag]"
    :[flag] "=&r"(flag));
    std::cout << flag << std::endl;
    cpuState->setFlags(flag);
    cpuState->writeToDataRegisters(register1, val);
}



#endif //VIRTUAL_MACHINE_ASSIGNFUNCTOR_H
