//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "VdbCli/Commands/CommandWrapper.h"


CommandWrapper::CommandWrapper(VDBCommand command, std::vector<std::string> _arguments):
vdbCommand(command), arguments(_arguments){}

VDBCommand CommandWrapper::getVdbCommand() const {
    return vdbCommand;
}

const std::vector<std::string> &CommandWrapper::getArguments() const {
    return arguments;
}
