//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_PARSER_H
#define VIRTUAL_MACHINE_PARSER_H

#include <vector>
#include <string>
#include <VdbCli/Commands/CommandWrapper.h>

class Parser{
public:
    CommandWrapper parse(std::vector<std::string> tokens);
};

#endif //VIRTUAL_MACHINE_PARSER_H
