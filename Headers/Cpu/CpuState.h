
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

        CpuState(uint32_t ip, uint64_t ir,
                 std::vector <uint8_t> generalPurposeRegisters, std::vector <uint32_t> addressRegisters);

        uint8_t getByte(uint32_t address);

        uint16_t getWord(uint32_t address);

        uint32_t getDWord(uint32_t address);

        uint64_t getQWord(uint32_t address);

        void writeByteToRegisters(uint8_t address, uint8_t data);

        void writeWordToRegisters(uint16_t address, uint16_t data);

        void writeDWordToRegisters(uint32_t address, uint32_t data);

        void writeQWordToRegisters(uint64_t address, uint64_t data);
    };
}

#endif //VIRTUAL_MACHINE_CPUSTATE_H
