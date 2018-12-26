//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_LANGUAGECONSTANTS_H
#define VIRTUAL_MACHINE_LANGUAGECONSTANTS_H

namespace lang {
    enum Operation {
        NOP = 0,
        JUMP,
        ASSIGN,
        MOV,
        SWAP,
        AND,
        OR,
        XOR,
        NOT,
        NAND,
        NOR,
        ADD,
        SUB,
        MUL,
        DIV,
        INC,
        DEC,
        PUSH,
        POP,
        CALL,
        RET,
        EXIT,
        LOAD,
        STORE,
        BREAK = 127,
        SIZE_DEFINER = 120
    };
}

#endif //VIRTUAL_MACHINE_LANGUAGECONSTANTS_H
