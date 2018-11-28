//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include <Cpu/CPUConstants.h>
#include "Cpu/CPU.h"

cpu::CPU::CPU(Memory *_memory) :
        vMemory(_memory),
        cpuState(0,0,std::vector<uint8_t>(DATA_REGISTERS_COUNT,0),
                 std::vector<uint32_t>(ADDRESS_REGISTERS_COUNT,0)){}

void cpu::CPU::fetch() {
    cpuState.ir = vMemory->read<uint64_t>(cpuState.ip);
}

void cpu::CPU::decode() {
    instruction = new Instruction(cpuState.ir);
}

void cpu::CPU::execute() {
    instructionFunctors[instruction->getOpCode()];
}

void cpu::CPU::incrementIP() {
	incrementIP(1);
}

void cpu::CPU::incrementIP(uint32_t offset) {
    cpuState.ip += offset;
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
