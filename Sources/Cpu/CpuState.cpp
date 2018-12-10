
#include "Cpu/CpuState.h"

cpu::CpuState::CpuState(uint32_t _ip, uint64_t _ir, uint32_t _sf, uint32_t _sp,
                        std::vector<uint8_t> _generalPurposeRegisters,
                        std::vector<uint32_t> _addressRegisters) : ip(_ip), ir(_ir), sf(_sf), sp(_sp), bdr(0),
                                                                  generalPurposeRegisters(_generalPurposeRegisters), addressRegisters(_addressRegisters) {

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

