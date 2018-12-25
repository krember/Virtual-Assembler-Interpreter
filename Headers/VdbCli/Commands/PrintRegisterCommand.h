//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_PRINTREGISTERCOMMAND_H
#define VIRTUAL_MACHINE_PRINTREGISTERCOMMAND_H

#include <VM/Logging/ConsoleLogger.h>
#include "Command.h"

class PrintRegisterCommand: public Command {
public:
    explicit PrintRegisterCommand(vm::Debugger* debugger);
    void execute(CommandWrapper wrappedCommand) override;

private:
    ConsoleLogger *consoleLogger;
};


#endif //VIRTUAL_MACHINE_PRINTREGISTERCOMMAND_H
