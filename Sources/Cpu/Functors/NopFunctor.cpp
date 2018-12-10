//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Functors/NopFunctor.h"

cpu::NopFunctor::NopFunctor(cpu::CpuState *state) : InstructionFunctor(state) {

}

void cpu::NopFunctor::operator()(Instruction & instruction) {

}
