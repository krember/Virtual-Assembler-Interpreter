#ifndef VIRTUAL_MACHINE_CPUCONSTANTS_H
#define VIRTUAL_MACHINE_CPUCONSTANTS_H

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

#endif //VIRTUAL_MACHINE_CPUCONSTANTS_H