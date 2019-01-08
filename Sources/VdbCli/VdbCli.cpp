//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//


#include <VdbCli/VdbCli.h>
#include "VM/Logging/Logging.h"

VdbCli::VdbCli() : virtualMachine(new vm::VirtualMachine()),
             cliCore(new VdbCliCore(virtualMachine->getVdb())) {}

VdbCli::~VdbCli() {
    delete virtualMachine;
    delete cliCore;
}

void VdbCli::run(std::string filename) {
    virtualMachine->debug(filename);
    loop();
}

void VdbCli::loop() {
    std::string input;
    while(true) {
        try {
            std::cout << ">> ";
            std::getline(std::cin, input);
            if (input == "exit") { // Too lazy to do it in CliCore at night time
                break;
            }
            cliCore->execute(input);
        } catch(Exception & e) {
            Logging::logToAllLoggers(e.getMessage(), LoggingSeverity::WARNING);
        }
    }
}
