//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>
#include "Cpu/Functors/BinaryRegisterwiseFunctor.h"

cpu::BinaryRegisterwiseFunctor::BinaryRegisterwiseFunctor(cpu::CpuState *_cpuState) : InstructionFunctor(_cpuState) {}

void cpu::BinaryRegisterwiseFunctor::operator()(Instruction & instruction) {
    switch (instruction.getRegistersOrder()) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RR:
            execute(instruction.getDataSize(), instruction.getRegister1(), instruction.getRegister2());
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + std::to_string(instruction.getRegistersOrder()));
    }
}
