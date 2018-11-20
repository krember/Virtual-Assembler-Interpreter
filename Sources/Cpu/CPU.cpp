//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include "Cpu/CPU.h"

cpu::CPU::CPU(NorthBridge *northBridge) :
        vNorthBridge(northBridge),
        cpuState(0,0,std::vector<uint8_t>(DATA_REGISTERS_COUNT,0),
                 std::vector<uint32_t>(ADDRESS_REGISTERS_COUNT,0)){}

void cpu::CPU::fetch() {
    cpuState.ir = vNorthBridge->readInstructionFromMemory(cpuState.ip);
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

cpu::CpuState cpu::CPU::getState() const {
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
