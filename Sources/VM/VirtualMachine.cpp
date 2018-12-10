//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include <utility>
#include <Config/VMConstants.h>
#include "VM/VirtualMachine.h"
#include "Cpu/Instruction.h"

vm::VirtualMachine::VirtualMachine() : vMemory(new vm::Memory(vm::DEFAULT_MEMORY_SIZE, vm::DEFAULT_STACK_SIZE)),
                                       vCpu(new cpu::CPU(vMemory)),
                                       vFileLoader(new FileLoader(vMemory)),
                                       vdb(new Debugger(vCpu, vMemory)) {
    initialize();
}

void vm::VirtualMachine::initialize() {
}

void vm::VirtualMachine::execute(std::string fileName) {

    // TODO May be needed to wrap in try-catch
    vFileLoader->load(fileName);

    vCpu->run();
}

void vm::VirtualMachine::debug(std::string fileName) {
    try {
        vFileLoader->load(fileName);

        std::cout << vdb->nextCommand() << std::endl;
        vdb->stepIn();
        std::cout << vdb->nextCommand() << std::endl;
    } catch (Exception &e) {
        std::cout << e.getMessage() << std::endl;
    }
}
