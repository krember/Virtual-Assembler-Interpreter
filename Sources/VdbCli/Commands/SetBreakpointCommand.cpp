//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <Exceptions/CliException.h>
#include "VdbCli/Commands/SetBreakpointCommand.h"

SetBreakpointCommand::SetBreakpointCommand(vm::Debugger *debugger) : Command(debugger) {}

void SetBreakpointCommand::execute(CommandWrapper wrappedCommand) {
    if (wrappedCommand.getVdbCommand() != VDBCommand::BREAK){
        throw CliException(VDBCommand::BREAK, wrappedCommand.getVdbCommand());
    }
    if(wrappedCommand.getArguments().size() != 1) {
        throw CliException("1", wrappedCommand.getArguments().size());
    }
    debugger->setBreakpoint(std::strtol(wrappedCommand.getArguments()[0].c_str(), nullptr, 10));
}
