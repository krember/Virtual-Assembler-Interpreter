//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <Cpu/CpuState.h>
#include "Cpu/Functors/InstructionFunctor.h"

cpu::InstructionFunctor::InstructionFunctor(cpu::CpuState *_state) : cpuState(_state) {

}