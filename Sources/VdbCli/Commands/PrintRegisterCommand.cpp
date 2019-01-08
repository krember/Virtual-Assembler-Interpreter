//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "VdbCli/Commands/PrintRegisterCommand.h"
#include "Exceptions/CliException.h"
#include "VM/Logging/Logging.h"

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
    std::string prefix = firstArgument + " = ";
    if (firstArgument == "ip") {
        consoleLogger -> out(prefix + std::to_string(debugger->state().ip));
    } else if (firstArgument == "ir") {
        consoleLogger->out(prefix + std::to_string(debugger->state().ir));
    } else if (firstArgument == "sp") {
        consoleLogger->out(prefix + std::to_string(debugger->state().sp));
    } else if (firstArgument == "sf") {
        consoleLogger->out(prefix + std::to_string(debugger->state().sf));
    } else if (firstArgument[0] == 'A') {
        firstArgument.erase(0, 1);
        long index = std::strtol(firstArgument.c_str(), nullptr, 10);
        if (debugger->state().addressRegisters.size() > index) {
            consoleLogger->out(prefix + std::to_string(debugger->state().readFromAddressRegister(index)));
        }
    } else if (firstArgument[0] == 'R') {
        firstArgument.erase(0, 1);
        long index = std::strtol(firstArgument.c_str(), nullptr, 10);
        if(firstArgument != std::to_string(index)) {
            throw CliException("Unknown register name.");
        }
        if (arguments.size() == 1) {
            consoleLogger->out(prefix + std::to_string(debugger->state().readFromDataRegister<uint8_t>(index)));
            std::cout << std::endl;
            return;
        }

        if (arguments[1] != "-s") {
            throw CliException("No valid parameter " + arguments[1] + " found for print command");
        }

        if (arguments[2] == "B") {
            consoleLogger->out(prefix +std::to_string(debugger->state().readFromDataRegister<uint8_t>(index)));
        } else if (arguments[2] == "W") {
            consoleLogger->out(prefix +std::to_string(debugger->state().readFromDataRegister<uint16_t>(index)));
        } else if (arguments[2] == "DW") {
            consoleLogger->out(prefix +std::to_string(debugger->state().readFromDataRegister<uint32_t>(index)));
        } else if (arguments[2] == "QW") {
            consoleLogger->out(prefix +std::to_string(debugger->state().readFromDataRegister<uint64_t>(index)));
        } else {
            throw CliException("Unknown value type.");
        }
    } else {
        throw CliException("Unknown register name.");
    }
    std::cout << std::endl;
    if (arguments.size() == 3 && arguments[1] == "-s" && prefix[0] != 'R') {
        Logging::logToAllLoggers("Ignored size parameter", LoggingSeverity::WARNING);
    }
}