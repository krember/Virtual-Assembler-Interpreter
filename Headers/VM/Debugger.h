//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_DEBUGGER_H
#define VIRTUAL_MACHINE_DEBUGGER_H

#include <Cpu/CPU.h>
#include <map>

namespace vm {
    class Debugger {
    public:
        static const uint64_t BREAKPOINT_INSTRUCTION = 0xFF00000000000000;

        Debugger(cpu::CPU * vCPU, vm::Memory * vMemory);

        void setBreakpoint(uint32_t address);
        void recoverBreakpoint(uint32_t address);
        void stepIn();
        void stepOver();
        void run();

        uint32_t nextCommand();
        cpu::CpuState state();
    private:
        vm::Memory * vMemory;
        cpu::CPU * vCpu;

        std::map<uint32_t, uint64_t> stashedInstructions;
    };
}

#endif //VIRTUAL_MACHINE_DEBUGGER_H
