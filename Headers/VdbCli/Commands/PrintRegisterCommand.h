//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_PRINTREGISTERCOMMAND_H
#define VIRTUAL_MACHINE_PRINTREGISTERCOMMAND_H

#include "Command.h"

class PrintRegisterCommand: public Command {
public:
    PrintRegisterCommand(vm::Debugger* debugger);
    void execute(CommandWrapper wrappedCommand);
};


#endif //VIRTUAL_MACHINE_PRINTREGISTERCOMMAND_H
