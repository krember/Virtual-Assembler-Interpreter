//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include <utility>
#include <Config/VMConstants.h>
#include <VM/Logging/ConsoleLogger.h>
#include <VM/Logging/Logging.h>
#include "VM/VirtualMachine.h"
#include "Cpu/Instruction.h"

vm::VirtualMachine::VirtualMachine() : vMemory(new vm::Memory(vm::DEFAULT_MEMORY_SIZE, vm::DEFAULT_STACK_SIZE)),
                                       vCpu(new cpu::CPU(vMemory, vm::DEFAULT_MEMORY_SIZE, vm::DEFAULT_STACK_SIZE)),
                                       vFileLoader(new FileLoader(vMemory)),
                                       vdb(new Debugger(vCpu, vMemory)) {
    initialize();
}

void vm::VirtualMachine::initialize() {
    ConsoleLogger* consoleLogger = ConsoleLogger::getInstance();
    Logging::registerLogger(consoleLogger);
}

void vm::VirtualMachine::execute(std::string fileName) {
    try {
        auto result = vFileLoader->load(fileName);
        vCpu->setIp(result.first);

        vCpu->run();
    } catch (Exception & e) {
        Logging::logToAllLoggers(e.getMessage(), LoggingSeverity::SEVERE);
    }
}

void vm::VirtualMachine::debug(std::string fileName) {
    try {
        auto result = vFileLoader->load(fileName);
        vCpu->setIp(result.first);
    } catch (Exception &e) {
        Logging::logToAllLoggers(e.getMessage(), LoggingSeverity::SEVERE);
    }
}

vm::Debugger *vm::VirtualMachine::getVdb() {
    return vdb;
}
