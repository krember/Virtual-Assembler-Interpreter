//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_VIRTUALMACHINE_H
#define VIRTUAL_MACHINE_VIRTUALMACHINE_H

#include <string>
#include "Cpu/CPU.h"
#include "VM/Memory.h"
#include "StructuredFile.h"
#include "VM/FileLoader.h"

namespace vm {
    class VirtualMachine {
    private:
        /* Private members */
        Memory *vMemory;
        cpu::CPU *vCpu;
        FileLoader *vFileLoader;

    public:
        /* Public interface */
        VirtualMachine();

        void execute(std::string fileName);  // Executes content of the given file (executable)
    };
}

#endif //VIRTUAL_MACHINE_VIRTUALMACHINE_H
