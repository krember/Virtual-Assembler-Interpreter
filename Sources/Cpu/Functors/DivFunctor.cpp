//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/1/2018.
//

#include "Cpu/Functors/DivFunctor.h"
#include <Exceptions/ExecutionException.h>
#include <Cpu/CpuState.h>
#include <Config/CPUConstants.h>

cpu::DivFunctor::DivFunctor(cpu::CpuState *_cpuState) : BinaryRegisterwiseFunctor(_cpuState) {}

void cpu::DivFunctor::execute(uint8_t dataSize, uint8_t register1, uint8_t register2) {
    switch (dataSize) {
        case DataSize::B:
            executeOp<uint8_t>(register1, register2);
            break;
        case DataSize::W:
            executeOp<uint16_t>(register1, register2);
            break;
        case DataSize::DW:
            executeOp<uint32_t>(register1, register2);
            break;
        case DataSize::QW:
            executeOp<uint64_t>(register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + std::to_string(dataSize));
    }
}