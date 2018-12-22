
#ifndef VIRTUAL_MACHINE_CPUSTATE_H
#define VIRTUAL_MACHINE_CPUSTATE_H

#include <vector>
#include <iostream>
#include "Flags.h"

namespace cpu {
    struct CpuState {
    public:
        uint32_t ip;
        uint32_t sf;
        uint32_t sp;
        uint64_t ir;
        uint8_t bdr;
        std::vector<uint8_t> generalPurposeRegisters; // R_something
        std::vector<uint32_t> addressRegisters; // A_something
        Flags flags;
        uint32_t memorySize;
        uint32_t stackSize;

        CpuState() : ip(0), ir(0), sf(0), sp(0), bdr(0), generalPurposeRegisters(64), addressRegisters(16) {
            generalPurposeRegisters[0] = 1;
            generalPurposeRegisters[1] = 2;
            generalPurposeRegisters[2] = 3;
            generalPurposeRegisters[3] = 4;
            generalPurposeRegisters[4] = 1;
            generalPurposeRegisters[5] = 2;
            generalPurposeRegisters[6] = 3;
            generalPurposeRegisters[7] = 4;
            addressRegisters[0] = 1;
            addressRegisters[1] = 2;
            addressRegisters[2] = 3;
            addressRegisters[3] = 4;
            addressRegisters[4] = 1;
            addressRegisters[5] = 2;
            addressRegisters[6] = 3;
            addressRegisters[7] = 4;
        }; //TODO for test reasons

        CpuState(uint32_t ip, uint64_t ir, uint32_t sf, uint32_t sp, uint32_t _memorySize, uint32_t _stackSize,
                 std::vector<uint8_t> generalPurposeRegisters, std::vector<uint32_t> addressRegisters);

        template<typename valueType>
        valueType readFromDataRegister(uint8_t address);

        template<typename valueType>
        void writeToDataRegisters(uint8_t address, valueType data);

        template<typename valueType>
        valueType readFromAddressRegister(uint8_t address);

        template<typename valueType>
        void writeToAddressRegisters(uint8_t address, valueType data);

        const Flags &getFlags();

        void setFlags(Flags &_flags);
        void setFlags(uint16_t _value);
    };
}

template<typename valueType>
valueType cpu::CpuState::readFromDataRegister(uint8_t address) {
    return *reinterpret_cast<valueType *>(&generalPurposeRegisters[0] + address);
}

template<typename valueType>
void cpu::CpuState::writeToDataRegisters(uint8_t address, valueType data) {
//    std::cout << generalPurposeRegisters[0] << std::endl;
    *reinterpret_cast<valueType *>(&generalPurposeRegisters[0] + address) = data;
}

template<typename valueType>
valueType cpu::CpuState::readFromAddressRegister(uint8_t address) {
    return *reinterpret_cast<valueType *>(&addressRegisters[0] + address);
}

template<typename valueType>
void cpu::CpuState::writeToAddressRegisters(uint8_t address, valueType data) {
    *reinterpret_cast<valueType *>(&addressRegisters[0] + address) = data;
}

#endif //VIRTUAL_MACHINE_CPUSTATE_H