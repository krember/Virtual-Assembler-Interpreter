//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_DEBUGGER_H
#define VIRTUAL_MACHINE_DEBUGGER_H

#include <Cpu/CPU.h>
#include <map>
#include <ObjectFile/SymbolTable.h>

namespace vm {
    class Debugger {
    public:
        static const uint64_t BREAKPOINT_INSTRUCTION = 0x000000000000007F;

        Debugger(cpu::CPU * vCPU, vm::Memory * vMemory);

        void setBreakpoint(uint32_t address);
        void removeBreakpoint(uint32_t address);
        void stepIn();
        void stepOver();
        void run();

        uint32_t nextCommand();
        cpu::CpuState state();

        std::vector<std::string> getStackTrace();
        const SymbolTable &getSymbolTable() const;
        void setSymbolTable(const SymbolTable &symbolTable);
    private:
        vm::Memory * vMemory;
        cpu::CPU *vCpu;
        SymbolTable symbolTable;

        std::map<uint32_t, uint64_t> stashedInstructions;

        void getStackTrace(std::vector<std::string> &functions, uint32_t sf, cpu::Instruction*);
    };
}

#endif //VIRTUAL_MACHINE_DEBUGGER_H
