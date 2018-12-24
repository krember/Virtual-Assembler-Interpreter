//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_STEPOVERCOMMAND_H
#define VIRTUAL_MACHINE_STEPOVERCOMMAND_H

#include "Command.h"

class StepOverCommand: public Command {
public:
    StepOverCommand(vm::Debugger* debugger);
    void execute(CommandWrapper wrappedCommand);
};


#endif //VIRTUAL_MACHINE_STEPOVER_H
