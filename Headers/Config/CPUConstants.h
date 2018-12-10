#ifndef VIRTUAL_MACHINE_CPUCONSTANTS_H
#define VIRTUAL_MACHINE_CPUCONSTANTS_H

#include <cstdio>
#include <cstdint>

namespace cpu {
    enum DataSize {
        B,
        W,
        DW,
        QW
    };

    enum JumpCondition {
        JE,
        JNE,
        JA,
        JAE,
        JB,
        JBE,
        JG,
        JGE,
        JL,
        JLE,
        JO,
        JNO,
        JS,
        JNS
    };

    enum RegisterOrder{
        AA,
        AR,
        RA,
        RR
    };

    const uint32_t ADDRESS_REGISTERS_COUNT = 16;
    const uint32_t DATA_REGISTERS_COUNT = 64;
    const uint32_t COMMAND_SIZE = 8;
    const uint8_t BREAK_EXIT_CODE = 1;
    const uint8_t HALT_EXIT_CODE = 2;
}


#endif //VIRTUAL_MACHINE_CPUCONSTANTS_H