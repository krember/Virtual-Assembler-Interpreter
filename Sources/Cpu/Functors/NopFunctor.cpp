//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Functors/NopFunctor.h"

cpu::NopFunctor::NopFunctor(cpu::CpuState *state) : InstructionFunctor(state) {

}

void cpu::NopFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder, uint8_t register1,
                                 uint8_t register2, uint32_t literal) {

}
