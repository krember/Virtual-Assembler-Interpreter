//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include <utility>
#include <Config/VMConstants.h>
#include "../Headers/VirtualMachine.h"
#include "../Headers/Instruction.h"

VirtualMachine::VirtualMachine() : vMemory(new Memory(vm::DEFAULT_MEMORY_SIZE, vm::DEFAULT_STACK_SIZE)),
                                   vCpu(new cpu::CPU(vMemory)),
                                   vConsole(new Console()),
                                   vFileLoader(new FileLoader(vMemory)) {}

void VirtualMachine::execute(std::string fileName) {

    // TODO May be needed to wrap in try-catch
    vFileLoader->load(fileName);

    // TODO translate to binary code
    //TODO: load to Memory
    vCpu->run();
}