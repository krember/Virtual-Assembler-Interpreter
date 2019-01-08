//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <Exceptions/ExecutionException.h>
#include <VM/Logging/ConsoleLogger.h>
#include "VM/Debugger.h"

vm::Debugger::Debugger(cpu::CPU *_vCpu, vm::Memory *_vMemory) : vMemory(_vMemory), vCpu(_vCpu)  {

}

void vm::Debugger::stepIn() {
    vCpu->step();
    if(vCpu->state().bdr == cpu::BREAK_EXIT_CODE) {
        removeBreakpoint(vCpu->state().ip);
    }
    if(vCpu->state().bdr == cpu::HALT_EXIT_CODE) {
        ConsoleLogger::getInstance()->out("Execution successfully finished.");
    }
}

void vm::Debugger::stepOver() {
    setBreakpoint(vCpu->state().ip + cpu::COMMAND_SIZE);
    run();
}

void vm::Debugger::run() {
    vCpu->run();
    if(vCpu->state().bdr == cpu::BREAK_EXIT_CODE) {
        removeBreakpoint(vCpu->state().ip);
    }
    if(vCpu->state().bdr == cpu::HALT_EXIT_CODE) {
        ConsoleLogger::getInstance()->out("Execution successfully finished.");
    }
}

cpu::CpuState vm::Debugger::state() {
    return vCpu->state();
}

uint32_t vm::Debugger::nextCommand() {
    return vMemory->read<uint32_t>(vCpu->state().ip);
}

void vm::Debugger::setBreakpoint(uint32_t address) {
    stashedInstructions.insert(std::pair<uint32_t, uint64_t>(address, vMemory->read<uint64_t>(address)));
    vMemory->write(address, BREAKPOINT_INSTRUCTION);
}

void vm::Debugger::removeBreakpoint(uint32_t address) {
    if(stashedInstructions.find(address) == stashedInstructions.end()) {
        throw ExecutionException("No breakpoints found at location " + std::to_string(address));
    }
    vMemory->write(address, stashedInstructions.at(address));
    stashedInstructions.erase(address);
}

const SymbolTable &vm::Debugger::getSymbolTable() const {
    return symbolTable;
}

void vm::Debugger::setSymbolTable(const SymbolTable &symbolTable) {
    Debugger::symbolTable = symbolTable;
}

void vm::Debugger::getStackTrace(std::vector<std::string> &functions, uint32_t sf, cpu::Instruction* instruction) {
    if(sf == vCpu->state().memorySize) {
        functions.push_back("Main");
        return;
    }

    getStackTrace(functions, vMemory->read<uint32_t>(sf), instruction);

    uint32_t ip = vMemory->read<uint32_t>(sf+4) - cpu::COMMAND_SIZE;
    uint64_t command = vMemory->read<uint64_t>(ip);
    instruction->init(command);
    if(instruction->getOpCode() - 1 == lang::CALL) {
        for (auto const& x : symbolTable.getTable())
        {
            if(x.second == instruction->getLiteral()) {
                functions.push_back(x.first);
                break;
            }
        }
    }
}

std::vector<std::string> vm::Debugger::getStackTrace() {
    cpu::Instruction* instruction = new cpu::Instruction();
    std::vector<std::string> functions;

    getStackTrace(functions, vCpu->state().sf, instruction);
    return functions;
}
