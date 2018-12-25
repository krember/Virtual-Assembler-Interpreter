//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_COMMANDS_H
#define VIRTUAL_MACHINE_COMMANDS_H

enum VDBCommand {
    BREAK = 0,
    R_BREAK,
    STACK_TRACE,
    STEP_IN,
    STEP_OVER,
    CONTINUE,
    PRINT,
    INVALID_COMMAND
};

#endif //VIRTUAL_MACHINE_COMMANDS_H
