//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_LANGUAGECONSTANTS_H
#define VIRTUAL_MACHINE_LANGUAGECONSTANTS_H

namespace lang {
    enum Operation {
        NOP = 1,
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
        SIZE_DEFINER = 120
    };
}

#endif //VIRTUAL_MACHINE_LANGUAGECONSTANTS_H
