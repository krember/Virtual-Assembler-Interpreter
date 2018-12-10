//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Functors/BreakFunctor.h"

cpu::BreakFunctor::BreakFunctor(cpu::CpuState *state) : InstructionFunctor(state) {

}

void cpu::BreakFunctor::operator()(Instruction & instruction) {
    cpuState->bdr = 1;
    cpuState->ip -= COMMAND_SIZE;
}
