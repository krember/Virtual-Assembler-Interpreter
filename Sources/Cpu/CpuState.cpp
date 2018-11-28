
#include "Cpu/CpuState.h"

cpu::CpuState::CpuState(uint32_t _ip, uint64_t _ir, std::vector<uint8_t> _generalPurposeRegisters,
                        std::vector<uint32_t> _addressRegisters) : ip(_ip),ir(_ir),
                                                                  generalPurposeRegisters(_generalPurposeRegisters), addressRegisters(_addressRegisters) {

}

uint32_t cpu::CpuState::getIp() {
    return ip;
}

void cpu::CpuState::setIp(uint32_t ip) {
    CpuState::ip = ip;
}

uint64_t cpu::CpuState::getIr() {
    return ir;
}

void cpu::CpuState::setIr(uint64_t ir) {
    CpuState::ir = ir;
}

cpu::Flags &cpu::CpuState::getFlags() {
    return flags;
}

void cpu::CpuState::setFlags(cpu::Flags &_flags) {
    CpuState::flags = flags;
}

void cpu::CpuState::setFlags(uint16_t _value) {
    flags.setFlags(_value);
}