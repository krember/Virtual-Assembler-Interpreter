//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_SETBREAKPOINTCOMMAND_H
#define VIRTUAL_MACHINE_SETBREAKPOINTCOMMAND_H

#include "Command.h"
#include "VM/Debugger.h"

class SetBreakpointCommand: public Command {
public:
    explicit SetBreakpointCommand(vm::Debugger* debugger);
    void execute(CommandWrapper wrappedCommand) override;
};



#endif //VIRTUAL_MACHINE_SETBREAKPOINT_H
