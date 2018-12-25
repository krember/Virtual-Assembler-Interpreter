//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_COMMANDWRAPPER_H
#define VIRTUAL_MACHINE_COMMANDWRAPPER_H


#include <VdbCli/Definitions.h>
#include <vector>
#include <string>
#include <VdbCli/Definitions.h>

class CommandWrapper {
public:
    CommandWrapper(VDBCommand command, std::vector <std::string> _arguments);

    VDBCommand getVdbCommand() const;
    const std::vector<std::string> &getArguments() const;

private:
    VDBCommand vdbCommand;
    std::vector <std::string> arguments;
};


#endif //VIRTUAL_MACHINE_COMMANDWRAPPER_H
