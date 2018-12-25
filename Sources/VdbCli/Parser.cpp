//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <VdbCli/Commands/CommandWrapper.h>
#include "VdbCli/Utils.h"
#include "VdbCli/Parser.h"

CommandWrapper Parser::parse(std::vector<std::string> tokens) {
    VDBCommand vdbCommand = Utils::getCommandFrom(tokens[0]);
    tokens.erase(tokens.begin());
    return CommandWrapper(vdbCommand, tokens);
}


