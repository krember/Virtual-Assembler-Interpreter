//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "VdbCli/Commands/PrintRegisterCommand.h"
#include "Exceptions/CliException.h"

PrintRegisterCommand::PrintRegisterCommand(vm::Debugger *_debugger) : Command(_debugger),
                                                                      consoleLogger(ConsoleLogger::getInstance()) {}

void PrintRegisterCommand::execute(CommandWrapper wrappedCommand) {
    if (wrappedCommand.getVdbCommand() != VDBCommand::PRINT) {
        throw CliException(VDBCommand::PRINT, wrappedCommand.getVdbCommand());
    }

    std::vector<std::string> arguments = wrappedCommand.getArguments();
    if (arguments.size() != 1 && arguments.size() != 3) {
        throw CliException("1 or 3", wrappedCommand.getArguments().size());
    }
    std::string firstArgument = arguments[0];
    consoleLogger->out(firstArgument + " = ");
    if (firstArgument == "ip") {
        consoleLogger -> out(std::to_string(debugger->state().ip));
    } else if (firstArgument == "ir") {
        consoleLogger->out(std::to_string(debugger->state().ir));
    } else if (firstArgument == "sp") {
        consoleLogger->out(std::to_string(debugger->state().sp));
    } else if (firstArgument == "sf") {
        consoleLogger->out(std::to_string(debugger->state().sf));
    } else if (firstArgument[0] == 'A') {
        firstArgument.erase(0, 1);
        long index = std::strtol(firstArgument.c_str(), nullptr, 10);
        if (debugger->state().addressRegisters.size() > index) {
            consoleLogger->out(std::to_string(debugger->state().readFromAddressRegister(index)));
        }
    } else if (firstArgument[0] == 'R') {
        firstArgument.erase(0, 1);
        long index = std::strtol(firstArgument.c_str(), nullptr, 10);
        if (arguments.size() == 1) {
            consoleLogger->out(std::to_string(debugger->state().readFromDataRegister<uint8_t>(index)));
            consoleLogger->out("\n");
            return;
        }

        if (arguments[1] != "-s") {
            throw CliException("No valid parameter " + arguments[1] + " found for print command");
        }

        if (arguments[2] == "B") {
            consoleLogger->out(std::to_string(debugger->state().readFromDataRegister<uint8_t>(index)));
        } else if (arguments[2] == "W") {
            consoleLogger->out(std::to_string(debugger->state().readFromDataRegister<uint16_t>(index)));
        } else if (arguments[2] == "DW") {
            consoleLogger->out(std::to_string(debugger->state().readFromDataRegister<uint32_t>(index)));
        } else if (arguments[2] == "QW") {
            consoleLogger->out(std::to_string(debugger->state().readFromDataRegister<uint64_t>(index)));
        } else {
            throw CliException("Unknown value type.");
        }
    } else {
        throw CliException("Unknown register name.");
    }
    consoleLogger->out("\n");
    if (arguments.size() == 3 && arguments[1] == "-s" && firstArgument[0] != 'R') {
        //TODO: Warn about value type ignore.
    }
}