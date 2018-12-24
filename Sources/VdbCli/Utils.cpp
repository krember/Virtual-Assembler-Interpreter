//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <VdbCli/Utils.h>

VDBCommand Utils::getCommandFrom(std::string commandStr) {
    if (commandStr == "break")
        return VDBCommand::BREAK;
    if (commandStr == "continue")
        return VDBCommand::CONTINUE;
    if (commandStr == "print")
        return VDBCommand::PRINT;
    if (commandStr == "rbreak")
        return VDBCommand::R_BREAK;
    if (commandStr == "st")
        return VDBCommand::STACK_TRACE;
    if (commandStr == "step_in")
        return VDBCommand::STEP_IN;
    if (commandStr == "step_over")
        return VDBCommand::STEP_OVER;
    return VDBCommand::INVALID_COMMAND;
}

