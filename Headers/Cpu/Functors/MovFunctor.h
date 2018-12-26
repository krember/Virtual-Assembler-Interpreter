//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_MOVFUNCTOR_H
#define VIRTUAL_MACHINE_MOVFUNCTOR_H

#include <Cpu/CpuState.h>
#include "InstructionFunctor.h"
#include "BinaryRegisterwiseFunctor.h"

namespace cpu {
    class MovFunctor : public InstructionFunctor {
    public:
        explicit MovFunctor(cpu::CpuState *state);

        virtual void operator()(Instruction & instruction);

        virtual void execute(uint8_t registerOrder, uint8_t dataSize, uint8_t register1, uint8_t register2);

        template<typename T>
        void executeOp(uint8_t registerOrder, uint8_t register1, uint8_t register2);
    };
}

template<typename T>
void cpu::MovFunctor::executeOp(uint8_t registerOrder, uint8_t register1, uint8_t register2) {
    switch (registerOrder) {
        case RegisterOrder::AA:
            cpuState->writeToAddressRegisters(register1, cpuState->readFromAddressRegister(register2));
            return;
        case RegisterOrder::AR:
            cpuState->writeToAddressRegisters(register1, cpuState->readFromDataRegister<uint32_t>(register2));
            return;
        case RegisterOrder::RA:
            cpuState->writeToDataRegisters(register1, cpuState->readFromAddressRegister(register2));
            return;
        case RegisterOrder::RR:
            cpuState->writeToDataRegisters(register1, cpuState->readFromDataRegister<T>(register2));
            return;
        default:
            return;
    }
}


#endif //VIRTUAL_MACHINE_MOVFUNCTOR_H
