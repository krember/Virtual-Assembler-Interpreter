//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "VdbCli/Commands/ContinueCommand.h"
#include "Exceptions/CliException.h"

ContinueCommand::ContinueCommand(vm::Debugger* _debugger): Command(_debugger){}

void ContinueCommand::execute(CommandWrapper wrappedCommand) {
    if (wrappedCommand.getVdbCommand() != VDBCommand::CONTINUE){
        throw CliException(VDBCommand::CONTINUE, wrappedCommand.getVdbCommand());
    }
    if(!wrappedCommand.getArguments().empty()) {
        throw CliException("0", wrappedCommand.getArguments().size());
    }
    debugger->run();
}
