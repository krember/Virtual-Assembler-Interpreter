//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/1/2018.
//

#include "Cpu/Functors/DivFunctor.h"
#include <Exceptions/ExecutionException.h>
#include <Cpu/CpuState.h>
#include <Config/CPUConstants.h>

cpu::DivFunctor::DivFunctor(cpu::CpuState *_cpuState) : cpuState(_cpuState) {}

void cpu::DivFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                 uint8_t register1, uint8_t register2, uint32_t literal) {
    switch (registersOrder) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RR:
            div(dataSize, register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + registersOrder);
    }
}

void cpu::DivFunctor::div(uint8_t dataSize, uint8_t register1, uint8_t register2) {
    switch (dataSize) {
        case DataSize::B:
            executeDiv<uint8_t>(register1, register2);
            break;
        case DataSize::W:
            executeDiv<uint16_t>(register1, register2);
            break;
        case DataSize::DW:
            executeDiv<uint32_t>(register1, register2);
            break;
        case DataSize::QW:
            executeDiv<uint64_t>(register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + dataSize);
    }
}

