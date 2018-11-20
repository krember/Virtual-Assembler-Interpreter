//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include <utility>
#include "../Headers/VirtualMachine.h"
#include "../Headers/Instruction.h"

VirtualMachine::VirtualMachine() :  vMemory(new Memory()),
                                    vNorthBridge(new NorthBridge(vMemory)),
                                    vCpu(new cpu::CPU(vNorthBridge)),
                                    vConsole(new Console()),
                                    vFileLoader(new FileLoader()) {}

void VirtualMachine::execute(std::string fileName) {

    // TODO May be needed to wrap in try-catch
    StructuredFile structuredFile = vFileLoader->load(fileName);

    // TODO translate to binary code
    vMemory->loadFile(structuredFile);
    vCpu->run();
}