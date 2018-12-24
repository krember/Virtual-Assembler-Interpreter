
#include "Cpu/CpuState.h"

cpu::CpuState::CpuState(uint32_t _ip, uint64_t _ir, uint32_t _sf, uint32_t _sp, uint32_t _memorySize, uint32_t _stackSize,
                        std::vector<uint8_t> _generalPurposeRegisters,
                        std::vector<uint32_t> _addressRegisters) : ip(_ip), ir(_ir), sf(_sf), sp(_sp), bdr(0),
                                                                   generalPurposeRegisters(_generalPurposeRegisters), addressRegisters(_addressRegisters),
                                                                   memorySize(_memorySize), stackSize(_stackSize) {

}

void cpu::CpuState::setFlags(cpu::Flags &_flags) {
    CpuState::flags = flags;
}

void cpu::CpuState::setFlags(uint16_t _value) {
    flags.setFlags(_value);
}
const cpu::Flags &cpu::CpuState::getFlags() {
    return flags;
}

uint32_t cpu::CpuState::readFromAddressRegister(uint8_t address) {
    return addressRegisters.at(address);
}

void cpu::CpuState::writeToAddressRegisters(uint8_t address, uint32_t data) {
    addressRegisters.at(address) = data;
}