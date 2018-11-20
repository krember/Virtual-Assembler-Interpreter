
#include "Cpu/CpuState.h"

cpu::CpuState::CpuState(uint32_t _ip, uint64_t _ir, std::vector<uint8_t> _generalPurposeRegisters,
                        std::vector<uint32_t> _addressRegisters) : ip(_ip),ir(_ir),
                                                                  generalPurposeRegisters(_generalPurposeRegisters), addressRegisters(_addressRegisters) {

}

uint8_t cpu::CpuState::getByte(uint32_t address) {
    return generalPurposeRegisters.at(address);
}

uint16_t cpu::CpuState::getWord(uint32_t address) {
    return *reinterpret_cast<uint16_t *>(generalPurposeRegisters.data() + address);
}

uint32_t cpu::CpuState::getDWord(uint32_t address) {
    return *reinterpret_cast<uint32_t *>(generalPurposeRegisters.data() + address);
}

uint64_t cpu::CpuState::getQWord(uint32_t address) {
    return *reinterpret_cast<uint64_t *>(generalPurposeRegisters.data() + address);
}

void cpu::CpuState::writeByteToRegisters(uint8_t address, uint8_t data) {
    generalPurposeRegisters[address] = data;
}

void cpu::CpuState::writeWordToRegisters(uint16_t address, uint16_t data) {
    *reinterpret_cast<uint16_t *>(generalPurposeRegisters.data() + address) = data;
}

void cpu::CpuState::writeDWordToRegisters(uint32_t address, uint32_t data) {
    *reinterpret_cast<uint32_t *>(generalPurposeRegisters.data() + address) = data;
}

void cpu::CpuState::writeQWordToRegisters(uint64_t address, uint64_t data) {
    *reinterpret_cast<uint64_t *>(generalPurposeRegisters.data() + address) = data;
}