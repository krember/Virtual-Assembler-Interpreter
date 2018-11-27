
#include "Cpu/CpuState.h"

cpu::CpuState::CpuState(uint32_t _ip, uint64_t _ir, std::vector<uint8_t> _generalPurposeRegisters,
                        std::vector<uint32_t> _addressRegisters) : ip(_ip),ir(_ir),
                                                                  generalPurposeRegisters(_generalPurposeRegisters), addressRegisters(_addressRegisters) {

}