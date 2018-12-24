//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_TOKENIZER_H
#define VIRTUAL_MACHINE_TOKENIZER_H

#include <vector>
#include <string>

class Tokenizer {
public:
    std::vector<std::string> tokenize(std::string command);
};

#endif //VIRTUAL_MACHINE_TOKENIZER_H
