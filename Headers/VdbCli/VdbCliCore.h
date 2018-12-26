//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_VDBCLICORE_H
#define VIRTUAL_MACHINE_VDBCLICORE_H

#include "Tokenizer.h"
#include "Parser.h"
#include "Commands/Command.h"

class VdbCliCore {
public:
    explicit VdbCliCore(vm::Debugger* _debugger);
    ~VdbCliCore();
    void execute(std::string command);

private:
    Tokenizer* tokenizer;
    Parser* parser;
    vm::Debugger* debugger;
    std::vector<Command*> commands;

    void initCommands(std::vector<Command*> &commands);
};


#endif //VIRTUAL_MACHINE_VDBCLI_H
