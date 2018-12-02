//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include <Config/CPUConstants.h>
#include <Cpu/CPU.h>
#include <Cpu/Functors/SumFunctor.h>
#include <Cpu/Functors/SubFunctor.h>
#include <Cpu/Functors/MulFunctor.h>

#include "Cpu/CPU.h"

cpu::CPU::CPU(Memory *_memory) :
        vMemory(_memory),
        cpuState(0,0,std::vector<uint8_t>(DATA_REGISTERS_COUNT,0),
                 std::vector<uint32_t>(ADDRESS_REGISTERS_COUNT,0)){
    initFunctors(instructionFunctors);
}

void cpu::CPU::initFunctors(std::vector<cpu::InstructionFunctor *> &_instructionFunctors) {
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new SumFunctor(&cpuState));
    _instructionFunctors.push_back(new SubFunctor(&cpuState));
}

void cpu::CPU::fetch() {
    cpuState.ir = vMemory->read<uint64_t>(cpuState.ip);
}

void cpu::CPU::decode() {
    instruction = new Instruction(cpuState.ir);
}

void cpu::CPU::execute() {
    InstructionFunctor *functor = instructionFunctors[instruction->getOpCode()-1];
    (*functor)(instruction->getJumpExtension(),instruction->getDataSize(),
            instruction->getRegistersOrder(),instruction->getRegister1(),
            instruction->getRegister2(),instruction->getLiteral());
}

void cpu::CPU::incrementIP() {
    ++cpuState.ip;
}


const cpu::CpuState& cpu::CPU::state() const {
    return cpuState;
}

void cpu::CPU::run() {
    while(true) {
        fetch();
        decode();
        incrementIP();
        //TODO wait for enter
        execute();
    }
}
