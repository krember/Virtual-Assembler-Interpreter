//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>
#include "Cpu/Functors/BinaryRegisterwiseFunctor.h"

cpu::BinaryRegisterwiseFunctor::BinaryRegisterwiseFunctor(cpu::CpuState *_cpuState) : InstructionFunctor(_cpuState) {}

void cpu::BinaryRegisterwiseFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder, uint8_t register1,
                                 uint8_t register2, uint32_t literal) {
    switch (registersOrder) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RR:
            execute(dataSize, register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + registersOrder);
    }
}
