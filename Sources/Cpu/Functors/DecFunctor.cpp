//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/3/2018.
//

#include "Cpu/Functors/DecFunctor.h"
#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>

cpu::DecFunctor::DecFunctor(cpu::CpuState *_cpuState) : cpuState(_cpuState) {}

void cpu::DecFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder, uint8_t register1,
                                 uint8_t register2, uint32_t literal) {
    switch (registersOrder) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RR:
            decrement(dataSize, register1);
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + registersOrder);
    }
}

void cpu::DecFunctor::decrement(uint8_t dataSize, uint8_t register1) {
    switch (dataSize) {
        case DataSize::B:
            executeDec<uint8_t>(register1);
            break;
        case DataSize::W:
            executeDec<uint16_t>(register1);
            break;
        case DataSize::DW:
            executeDec<uint32_t>(register1);
            break;
        case DataSize::QW:
            executeDec<uint64_t>(register1);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + dataSize);
    }
}

