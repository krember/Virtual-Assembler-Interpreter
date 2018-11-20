//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_VIRTUALMACHINE_H
#define VIRTUAL_MACHINE_VIRTUALMACHINE_H

#include <string>
#include "Cpu/CPU.h"
#include "Memory.h"
#include "Console.h"
#include "StructuredFile.h"
#include "FileLoader.h"

class VirtualMachine {
private:
    /* Private members */
    Memory *vMemory;
    NorthBridge *vNorthBridge;
    cpu::CPU *vCpu;
    FileLoader *vFileLoader;
    Console *vConsole; // TODO: add keyboard

public:
    /* Public interface */
    VirtualMachine();

    void execute(std::string fileName);  // Executes content of the given file (executable)
};

#endif //VIRTUAL_MACHINE_VIRTUALMACHINE_H
