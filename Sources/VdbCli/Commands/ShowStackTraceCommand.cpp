//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <VdbCli/Commands/ShowStackTraceCommand.h>
#include <Exceptions/CliException.h>
#include <VM/Logging/ConsoleLogger.h>

#include "VdbCli/Commands/ShowStackTraceCommand.h"

ShowStackTraceCommand::ShowStackTraceCommand(vm::Debugger *debugger) : Command(debugger) {}

void ShowStackTraceCommand::execute(CommandWrapper wrappedCommand) {
    if (wrappedCommand.getVdbCommand() != VDBCommand::STACK_TRACE) {
        throw CliException(VDBCommand::STACK_TRACE, wrappedCommand.getVdbCommand());
    }

    if (!wrappedCommand.getArguments().empty()) {
        throw CliException("0", wrappedCommand.getArguments().size());
    }

    std::vector<std::string> st = debugger->getStackTrace();
    for(std::string & func : st) {
        ConsoleLogger::getInstance()->out(func + "\n");
    }
}
