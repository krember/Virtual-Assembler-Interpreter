//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <Exceptions/CliException.h>
#include "VdbCli/Commands/StepInCommand.h"

StepInCommand::StepInCommand(vm::Debugger *debugger) : Command(debugger) {}

void StepInCommand::execute(CommandWrapper wrappedCommand) {
    if (wrappedCommand.getVdbCommand() != VDBCommand::STEP_IN) {
        throw CliException(VDBCommand::STEP_IN, wrappedCommand.getVdbCommand());
    }

    if (!wrappedCommand.getArguments().empty()) {
        throw CliException("0", wrappedCommand.getArguments().size());
    }
    debugger->stepIn();
}
