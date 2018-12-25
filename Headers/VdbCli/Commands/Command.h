//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_COMMAND_H
#define VIRTUAL_MACHINE_COMMAND_H

#include <vector>
#include <string>
#include <VM/Debugger.h>
#include "VdbCli/Definitions.h"
#include "CommandWrapper.h"

class Command{
public:
    explicit Command(vm::Debugger *debugger) : debugger(debugger) {}

    virtual void execute(CommandWrapper wrappedCommand) = 0;
protected:
    vm::Debugger* debugger;
};

#endif //VIRTUAL_MACHINE_COMMAND_H
