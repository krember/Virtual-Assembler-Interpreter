//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/1/2018.
//

#include "Cpu/Functors/MulFunctor.h"
#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>

cpu::MulFunctor::MulFunctor(cpu::CpuState *_cpuState) : cpuState(_cpuState) {}

void cpu::MulFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                 uint8_t register1, uint8_t register2, uint32_t literal) {
    switch (registersOrder) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RR:
            mul(dataSize, register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + registersOrder);
    }
}

void cpu::MulFunctor::mul(uint8_t dataSize, uint8_t register1, uint8_t register2) {
    switch (dataSize) {
        case DataSize::B:
            executeMul<uint8_t>(register1, register2);
            break;
        case DataSize::W:
            executeMul<uint16_t>(register1, register2);
            break;
        case DataSize::DW:
            executeMul<uint32_t>(register1, register2);
            break;
        case DataSize::QW:
            executeMul<uint64_t>(register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + dataSize);
    }
}

