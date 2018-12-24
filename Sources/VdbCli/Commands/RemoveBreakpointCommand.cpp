//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "VdbCli/Commands/RemoveBreakpointCommand.h"
#include "Exceptions/CliException.h"

RemoveBreakpointCommand::RemoveBreakpointCommand(vm::Debugger* _debugger): Command(_debugger){}

void RemoveBreakpointCommand::execute(CommandWrapper wrappedCommand) {
    if (wrappedCommand.getVdbCommand() != VDBCommand::R_BREAK){
        throw CliException(VDBCommand::R_BREAK, wrappedCommand.getVdbCommand());
    }
    if(wrappedCommand.getArguments().size() != 1) {
        throw CliException("1", wrappedCommand.getArguments().size());
    }
    debugger->removeBreakpoint(std::strtol(wrappedCommand.getArguments()[0].c_str(), nullptr, 10));
}

