//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include <Config/CPUConstants.h>
#include <Cpu/CPU.h>
#include <Cpu/Functors/SumFunctor.h>
#include <Cpu/Functors/SubFunctor.h>
#include <Cpu/Functors/MulFunctor.h>
#include <Cpu/Functors/NopFunctor.h>
#include <Cpu/Functors/JumpFunctor.h>
#include <Cpu/Functors/AssignFunctor.h>
#include <Cpu/Functors/MovFunctor.h>
#include <Cpu/Functors/SwapFunctor.h>
#include <Cpu/Functors/AndFunctor.h>
#include <Cpu/Functors/OrFunctor.h>
#include <Cpu/Functors/XorFunctor.h>
#include <Cpu/Functors/NotFunctor.h>
#include <Cpu/Functors/NandFunctor.h>
#include <Cpu/Functors/NorFunctor.h>
#include <Cpu/Functors/DivFunctor.h>
#include <Cpu/Functors/IncFunctor.h>
#include <Cpu/Functors/DecFunctor.h>
#include <Config/VMConstants.h>
#include <Cpu/Functors/PushFunctor.h>
#include <Cpu/Functors/PopFunctor.h>
#include <Cpu/Functors/CallAddressFunctor.h>
#include <Cpu/Functors/RetFunctor.h>
#include <Cpu/Functors/ExitFunctor.h>
#include <Cpu/Functors/BreakFunctor.h>
#include <Cpu/Functors/LoadFunctor.h>
#include <Cpu/Functors/StoreFunctor.h>
#include <Cpu/Functors/PushSfFunctor.h>
#include <Cpu/Functors/PopSfFunctor.h>

#include "Cpu/CPU.h"

cpu::CPU::CPU(vm::Memory *_memory, uint32_t _memorySize, uint32_t _stackSize) :
        vMemory(_memory),
        cpuState(0, 0, _memorySize, _memorySize, _memorySize, _stackSize, std::vector<uint8_t>(DATA_REGISTERS_COUNT, 0),
                 std::vector<uint32_t>(ADDRESS_REGISTERS_COUNT,0)) {
    initFunctors(instructionFunctors);
}

void cpu::CPU::initFunctors(std::vector<cpu::InstructionFunctor *> &_instructionFunctors) {
    _instructionFunctors.push_back(new NopFunctor(&cpuState));
    _instructionFunctors.push_back(new JumpFunctor(&cpuState));
    _instructionFunctors.push_back(new AssignFunctor(&cpuState));
    _instructionFunctors.push_back(new MovFunctor(&cpuState));
    _instructionFunctors.push_back(new SwapFunctor(&cpuState));
    _instructionFunctors.push_back(new AndFunctor(&cpuState));
    _instructionFunctors.push_back(new OrFunctor(&cpuState));
    _instructionFunctors.push_back(new XorFunctor(&cpuState));
    _instructionFunctors.push_back(new NotFunctor(&cpuState));
    _instructionFunctors.push_back(new NandFunctor(&cpuState));
    _instructionFunctors.push_back(new NorFunctor(&cpuState));
    _instructionFunctors.push_back(new SumFunctor(&cpuState));
    _instructionFunctors.push_back(new SubFunctor(&cpuState));
    _instructionFunctors.push_back(new MulFunctor(&cpuState));
    _instructionFunctors.push_back(new DivFunctor(&cpuState));
    _instructionFunctors.push_back(new IncFunctor(&cpuState));
    _instructionFunctors.push_back(new DecFunctor(&cpuState));
    _instructionFunctors.push_back(new PushFunctor(&cpuState, vMemory));
    _instructionFunctors.push_back(new PopFunctor(&cpuState, vMemory));
    _instructionFunctors.push_back(new CallAddressFunctor(&cpuState, _instructionFunctors.at(lang::Operation::PUSH)));
    _instructionFunctors.push_back(new RetFunctor(&cpuState, _instructionFunctors.at(lang::Operation::POP)));
    _instructionFunctors.push_back(new ExitFunctor(&cpuState));
    _instructionFunctors.push_back(new LoadFunctor(&cpuState, vMemory));
    _instructionFunctors.push_back(new StoreFunctor(&cpuState, vMemory));
    _instructionFunctors.push_back(new PushSfFunctor(&cpuState, _instructionFunctors.at(lang::Operation::PUSH)));
    _instructionFunctors.push_back(new PopSfFunctor(&cpuState, _instructionFunctors.at(lang::Operation::POP)));

    _instructionFunctors.resize(127);
    _instructionFunctors.at(126) = new BreakFunctor(&cpuState);
}

void cpu::CPU::fetch() {
    cpuState.ir = vMemory->read<uint64_t>(cpuState.ip);
}

void cpu::CPU::decode(Instruction * instruction) {
    instruction->init(cpuState.ir);
}

void cpu::CPU::execute(Instruction * instruction) {
    InstructionFunctor *functor = instructionFunctors[instruction->getOpCode()-1];
    (*functor)(*instruction);
}


void cpu::CPU::incrementIP() {
    cpuState.ip += cpu::COMMAND_SIZE;
}

const cpu::CpuState& cpu::CPU::state() const {
    return cpuState;
}

void cpu::CPU::run() {
    cpuState.bdr = 0;
    Instruction* instruction = new Instruction();
    while(cpuState.bdr == 0) {
        fetch();
        decode(instruction);
        incrementIP();
        execute(instruction);
    }
    delete instruction;
}

void cpu::CPU::step() {
    cpuState.bdr = 0;
    Instruction instruction;
    fetch();
    decode(&instruction);
    incrementIP();
    execute(&instruction);
}

void cpu::CPU::setIp(uint32_t _ip) {
    cpuState.ip = _ip;
}
