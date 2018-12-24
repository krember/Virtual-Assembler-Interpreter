//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <VdbCli/Tokenizer.h>
#include <sstream>


std::vector<std::string> Tokenizer::tokenize(std::string command) {
    std::vector<std::string> tokens;
    std::istringstream iss(command);
    for (std::string _command; iss >> _command;) {
        tokens.push_back(_command);
    }
    return tokens;
}

