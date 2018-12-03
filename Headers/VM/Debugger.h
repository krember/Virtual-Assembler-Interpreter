//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_DEBUGGER_H
#define VIRTUAL_MACHINE_DEBUGGER_H

#include <Cpu/CPU.h>

namespace vm {
    class Debugger {
    public:
        Debugger(cpu::CPU * vCPU, vm::Memory * vMemory);

        void debug();

    private:
        vm::Memory * vMemory;
        cpu::CPU * vCpu;
    };
}

#endif //VIRTUAL_MACHINE_DEBUGGER_H
