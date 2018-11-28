
#ifndef VIRTUAL_MACHINE_CPUSTATE_H
#define VIRTUAL_MACHINE_CPUSTATE_H

#include <cstdint>
#include <vector>
#include "Flags.h"

namespace cpu {
    struct CpuState {
        uint32_t ip;
        uint64_t ir;
        std::vector <uint8_t> generalPurposeRegisters; // R_something
        std::vector <uint32_t> addressRegisters; // A_something
        Flags flags;

        CpuState() : ip(0), ir(0), generalPurposeRegisters(64), addressRegisters(16) {
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

        CpuState(uint32_t ip, uint64_t ir,
                 std::vector <uint8_t> generalPurposeRegisters, std::vector <uint32_t> addressRegisters);

        template <typename valueType>
        valueType readFromDataRegister(uint32_t address);

        template <typename valueType>
        void writeToDataRegisters(uint8_t address, valueType data);

        template <typename valueType>
        valueType readFromAddressRegister(uint32_t address);

        template <typename valueType>
        void writeToAddressRegisters(uint8_t address, valueType data);

        uint32_t getIp();

        void setIp(uint32_t ip);

        uint64_t getIr();

        void setIr(uint64_t ir);

        Flags &getFlags();

        void setFlags(Flags &_flags);
        void setFlags(uint16_t _value);
    };
}

template<typename valueType>
valueType cpu::CpuState::readFromDataRegister(uint32_t address) {
    return *reinterpret_cast<valueType *>(generalPurposeRegisters.data() + address);
}

template<typename valueType>
void cpu::CpuState::writeToDataRegisters(uint8_t address, valueType data) {
    *reinterpret_cast<valueType *>(generalPurposeRegisters.data() + address) = data;
}

template<typename valueType>
valueType cpu::CpuState::readFromAddressRegister(uint32_t address) {
    return *reinterpret_cast<valueType *>(addressRegisters.data() + address);
}

template<typename valueType>
void cpu::CpuState::writeToAddressRegisters(uint8_t address, valueType data) {
    *reinterpret_cast<valueType *>(addressRegisters.data() + address) = data;
}

#endif //VIRTUAL_MACHINE_CPUSTATE_H
