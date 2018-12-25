//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 12/1/2018.
//

#include "Cpu/Functors/AssignFunctor.h"
#include <Exceptions/ExecutionException.h>
#include <Cpu/CpuState.h>
#include <Config/CPUConstants.h>

cpu::AssignFunctor::AssignFunctor(cpu::CpuState *_cpuState) : InstructionFunctor(_cpuState) {}

void cpu::AssignFunctor::operator()(Instruction &instruction) {
    switch (instruction.getRegistersOrder()) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
            execute(instruction.getDataSize(), instruction.getRegister1(), instruction.getLiteral(), false);
            break;
        case RegisterOrder::RA:
        case RegisterOrder::RR:
            execute(instruction.getDataSize(), instruction.getRegister1(), instruction.getLiteral(), true);
            break;
        default:
            throw ExecutionException(
                    "Unrecognized register types found - " + std::to_string(instruction.getRegistersOrder()));
    }
}

void cpu::AssignFunctor::execute(uint8_t dataSize, uint8_t register1, uint32_t literal, bool isData) {
    switch (dataSize) {
        case DataSize::B:
            executeOp<uint8_t>(register1, literal, isData);
            break;
        case DataSize::W:
            executeOp<uint16_t>(register1, literal, isData);
            break;
        case DataSize::DW:
            executeOp<uint32_t>(register1, literal, isData);
            break;
        case DataSize::QW:
            executeOp<uint64_t>(register1, literal, isData);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + std::to_string(dataSize));
    }
}

