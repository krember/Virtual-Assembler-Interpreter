//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_SHOWSTACKTRACECOMMAND_H
#define VIRTUAL_MACHINE_SHOWSTACKTRACECOMMAND_H

#include "Command.h"

class ShowStackTraceCommand: public Command {
public:
    explicit ShowStackTraceCommand(vm::Debugger* debugger);
    void execute(CommandWrapper wrappedCommand) override;
};


#endif //VIRTUAL_MACHINE_SHOWSTACKTRACE_H
