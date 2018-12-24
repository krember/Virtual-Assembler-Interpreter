//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "VdbCli/Commands/StepOverCommand.h"
#include <Exceptions/CliException.h>

StepOverCommand::StepOverCommand(vm::Debugger *debugger) : Command(debugger) {}

void StepOverCommand::execute(CommandWrapper wrappedCommand) {
    if (wrappedCommand.getVdbCommand() != VDBCommand::STEP_IN) {
        throw CliException(VDBCommand::STACK_TRACE, wrappedCommand.getVdbCommand());
    }

    if (!wrappedCommand.getArguments().empty()) {
        throw CliException("0", wrappedCommand.getArguments().size());
    }
    debugger->stepOver();
}
