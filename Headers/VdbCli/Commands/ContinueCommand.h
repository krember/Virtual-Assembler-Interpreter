//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_CONTINUECOMMAND_H
#define VIRTUAL_MACHINE_CONTINUECOMMAND_H


#include "Command.h"
#include "VM/Debugger.h"

class ContinueCommand: public Command {
public:
    explicit ContinueCommand(vm::Debugger* debugger);
    void execute(CommandWrapper wrappedCommand) override;
};


#endif //VIRTUAL_MACHINE_CONTINUECOMMAND_H
