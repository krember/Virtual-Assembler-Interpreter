
#ifndef VIRTUAL_MACHINE_CPUSTATE_H
#define VIRTUAL_MACHINE_CPUSTATE_H

#include <cstdint>
#include <vector>

namespace cpu {
    struct CpuState {
        uint32_t ip;
        uint64_t ir;
        std::vector <uint8_t> generalPurposeRegisters; // R_something
        std::vector <uint32_t> addressRegisters; // A_something
        uint16_t fla

        CpuState(uint32_t ip, uint64_t ir,
                 std::vector <uint8_t> generalPurposeRegisters, std::vector <uint32_t> addressRegisters);

        template <typename valueType>
        valueType getRegister(uint32_t address);

        template <typename valueType>
        void writeToRegisters(uint8_t address, valueType data);
    };
}

template<typename valueType>
valueType cpu::CpuState::getRegister(uint32_t address) {
    return *reinterpret_cast<valueType *>(generalPurposeRegisters.data() + address);
}

template<typename valueType>
void cpu::CpuState::writeToRegisters(uint8_t address, valueType data) {
    *reinterpret_cast<valueType *>(generalPurposeRegisters.data() + address) = data;
}

#endif //VIRTUAL_MACHINE_CPUSTATE_H
