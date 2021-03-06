//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Functors/PushFunctor.h"
#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>

cpu::PushFunctor::PushFunctor(cpu::CpuState *_cpuState, vm::Memory *memory) : InstructionFunctor(_cpuState), vMemory(memory) {

}

void cpu::PushFunctor::operator()(Instruction & instruction) {
    switch (instruction.getRegistersOrder()) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RA:
        case RegisterOrder::RR:
            execute(instruction.getDataSize(), instruction.getRegister1());
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + instruction.getRegistersOrder());
    }
}

void cpu::PushFunctor::execute(uint8_t dataSize, uint8_t register1) {
    switch (dataSize) {
        case DataSize::B:
            executeOp<uint8_t>(register1);
            break;
        case DataSize::W:
            executeOp<uint16_t>(register1);
            break;
        case DataSize::DW:
            executeOp<uint32_t>(register1);
            break;
        case DataSize::QW:
            executeOp<uint64_t>(register1);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + dataSize);
    }
}
