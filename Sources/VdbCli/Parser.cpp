//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <VdbCli/Commands/CommandWrapper.h>
#include "VdbCli/Utils.h"
#include "VdbCli/Parser.h"

CommandWrapper Parser::parse(std::vector<std::string> tokens) {
    VDBCommand vdbCommand = Utils::getCommandFrom(tokens[0]);
    std::vector<std::string> arguments;
    if (vdbCommand != VDBCommand::INVALID_COMMAND) {
        for (int i = 1; i < tokens.size(); ++i) {
            arguments.push_back(tokens[i]);
        }
    }
    return CommandWrapper(vdbCommand, arguments);
}


