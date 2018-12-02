//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>
#include "Cpu/Functors/IncFunctor.h"

cpu::IncFunctor::IncFunctor(cpu::CpuState *_cpuState) : cpuState(_cpuState) {}

void cpu::IncFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                 uint8_t register1, uint8_t register2, uint32_t literal) {
    switch (registersOrder) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RA:
        case RegisterOrder::RR:
            inc(dataSize, register1);
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + registersOrder);
    }
}

void cpu::IncFunctor::inc(uint8_t dataSize, uint8_t register1) {
    switch (dataSize) {
        case DataSize::B:
            executeInc<uint8_t>(register1);
            break;
        case DataSize::W:
            executeInc<uint16_t>(register1);
            break;
        case DataSize::DW:
            executeInc<uint32_t>(register1);
            break;
        case DataSize::QW:
            executeInc<uint64_t>(register1);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + dataSize);
    }
}