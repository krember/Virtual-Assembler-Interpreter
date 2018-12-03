//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/1/2018.
//

#include "Cpu/Functors/AssignFunctor.h"
#include <Exceptions/ExecutionException.h>
#include <Cpu/CpuState.h>
#include <Config/CPUConstants.h>

cpu::AssignFunctor::AssignFunctor(cpu::CpuState *_cpuState) : InstructionFunctor(_cpuState) {}

void cpu::AssignFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder,
                                 uint8_t register1, uint8_t register2, uint32_t literal) {
    switch (registersOrder) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RA:
        case RegisterOrder::RR:
            execute(dataSize, register1, literal);
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + registersOrder);
    }
}

void cpu::AssignFunctor::execute(uint8_t dataSize, uint8_t register1, uint32_t literal) {
    switch (dataSize) {
        case DataSize::B:
            executeOp<uint8_t>(register1, literal);
            break;
        case DataSize::W:
            executeOp<uint16_t>(register1, literal);
            break;
        case DataSize::DW:
            executeOp<uint32_t>(register1, literal);
            break;
        case DataSize::QW:
            executeOp<uint64_t>(register1, literal);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + dataSize);
    }
}

