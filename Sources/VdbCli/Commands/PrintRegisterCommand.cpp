//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "VdbCli/Commands/PrintRegisterCommand.h"
#include "Exceptions/CliException.h"

PrintRegisterCommand::PrintRegisterCommand(vm::Debugger *_debugger) : Command(_debugger) {}

void PrintRegisterCommand::execute(CommandWrapper wrappedCommand) {
    if (wrappedCommand.getVdbCommand() != VDBCommand::PRINT) {
        throw CliException(VDBCommand::PRINT, wrappedCommand.getVdbCommand());
    }

    std::vector<std::string> arguments = wrappedCommand.getArguments();
    if (arguments.size() != 1 && arguments.size() != 3) {
        throw CliException("1 or 3", wrappedCommand.getArguments().size());
    }
    std::string firstArgument = arguments[0];
    std::cout << firstArgument << " = ";
    if (firstArgument == "ip") {
        std::cout << debugger->state().ip;
    } else if (firstArgument == "ir") {
        std::cout << debugger->state().ir;
    } else if (firstArgument == "sp") {
        std::cout << debugger->state().sp;
    } else if (firstArgument == "ir") {
        std::cout << debugger->state().ir;
    } else if (firstArgument == "sf") {
        std::cout << debugger->state().sf;
    } else if (firstArgument[0] == 'A') {
        firstArgument.erase(0, 1);
        long index = std::strtol(firstArgument.c_str(), nullptr,10);
        if (debugger->state().addressRegisters.size() > index) {
            std::cout << debugger->state().readFromAddressRegister(index);
        }
    } else if (firstArgument[0] == 'R') {
        firstArgument.erase(0, 1);
        long index = std::strtol(firstArgument.c_str(), nullptr,10);
        if (arguments.size() == 1) {
            std::cout << debugger->state().readFromDataRegister<uint8_t>(index);
            return;
        }

        if(arguments[1] != "-s") {
            throw CliException("No valid parameter " + arguments[1] + " found for print command");
        }

        if (arguments[2] == "B") {
            std::cout << debugger->state().readFromDataRegister<uint8_t>(index);
        } else if (arguments[2] == "W") {
                std::cout << debugger->state().readFromDataRegister<uint16_t>(index);
        } else if (arguments[2] == "DW") {
            std::cout << debugger->state().readFromDataRegister<uint32_t>(index);
        } else if (arguments[2] == "QW") {
            std::cout << debugger->state().readFromDataRegister<uint64_t>(index);
        } else {
            throw CliException("Unknown value type.");
        }
    } else {
        throw CliException("Unknown register name.");
    }
    if (arguments.size() == 3 && arguments[1] == "-s" && firstArgument[0] != 'R') {
        //TODO: Warn about value type ignore.
    }
}