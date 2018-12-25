//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_STEPINCOMMAND_H
#define VIRTUAL_MACHINE_STEPINCOMMAND_H

#include "Command.h"

class StepInCommand: public Command {
public:
    explicit StepInCommand(vm::Debugger* debugger);
    void execute(CommandWrapper wrappedCommand) override;
};


#endif //VIRTUAL_MACHINE_STEPIN_H
