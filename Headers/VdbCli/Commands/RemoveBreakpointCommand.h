//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_REMOVEBREAKPOINTCOMMAND_H
#define VIRTUAL_MACHINE_REMOVEBREAKPOINTCOMMAND_H

#include "Command.h"
#include "VM/Debugger.h"

class RemoveBreakpointCommand: public Command {
public:
    RemoveBreakpointCommand(vm::Debugger* debugger);
    void execute(CommandWrapper wrappedCommand);
};


#endif //VIRTUAL_MACHINE_REMOVEBREAKPOINTCOMMAND_H
