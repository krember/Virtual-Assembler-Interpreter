//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <VdbCli/Commands/SetBreakpointCommand.h>
#include <VdbCli/Commands/RemoveBreakpointCommand.h>
#include <VdbCli/Commands/ShowStackTraceCommand.h>
#include <VdbCli/Commands/StepInCommand.h>
#include <VdbCli/Commands/StepOverCommand.h>
#include <VdbCli/Commands/ContinueCommand.h>
#include <VdbCli/Commands/PrintRegisterCommand.h>
#include "VdbCli/VdbCliCore.h"

VdbCliCore::VdbCliCore(vm::Debugger* _debugger): tokenizer(new Tokenizer()), parser(new Parser()), debugger(_debugger) {
    initCommands(commands);
}

VdbCliCore::~VdbCliCore() {
    delete tokenizer;
    delete parser;
}

void VdbCliCore::initCommands(std::vector<Command *> &commands) {
    commands.push_back(new SetBreakpointCommand(debugger));
    commands.push_back(new RemoveBreakpointCommand(debugger));
    commands.push_back(new ShowStackTraceCommand(debugger));
    commands.push_back(new StepInCommand(debugger));
    commands.push_back(new StepOverCommand(debugger));
    commands.push_back(new ContinueCommand(debugger));
    commands.push_back(new PrintRegisterCommand(debugger));
}

void VdbCliCore::execute(std::string command) {
    std::vector<std::string> tokens = tokenizer->tokenize(command);
    if(tokens.empty()) {
        return;
    }
    CommandWrapper parsedCommand = parser->parse(tokens);
    commands[parsedCommand.getVdbCommand()]->execute(parsedCommand);
}
