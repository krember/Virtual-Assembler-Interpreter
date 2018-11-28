#ifndef VIRTUAL_MACHINE_CPUCONSTANTS_H
#define VIRTUAL_MACHINE_CPUCONSTANTS_H

#include <cstdio>

enum DataSize {
    B,
    W,
    DW,
    QW
};

//TODO : enum for jump command extesnion or smth like

enum RegisterOrder{
    AA,
    AR,
    RA,
    RR
};

const size_t ADDRESS_REGISTERS_COUNT = 16;
const size_t DATA_REGISTERS_COUNT = 64;
const size_t COMMAND_SIZE = 8;


#endif //VIRTUAL_MACHINE_CPUCONSTANTS_H