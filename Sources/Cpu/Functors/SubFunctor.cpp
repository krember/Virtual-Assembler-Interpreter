
#include <Exceptions/ExecutionException.h>
#include "Cpu/Functors/SubFunctor.h"

cpu::SubFunctor::SubFunctor(cpu::CPU *_cpu) : cpu(_cpu) {}

void cpu::SubFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder, uint8_t register1,
                                 uint8_t register2, uint32_t literal) {
    switch (registersOrder) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RR:
            sub(dataSize, register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + registersOrder);
    }
}

void cpu::SubFunctor::sub(uint8_t dataSize, uint8_t register1, uint8_t register2) {
    switch (dataSize) {
        case DataSize::B:
            cpu->cpuState.writeByteToRegisters(register1,
                                               cpu->cpuState.getByte(register1) + cpu->cpuState.getByte(register2));
            break;
        case DataSize::W:
            cpu->cpuState.writeWordToRegisters(register1,
                                               cpu->cpuState.getWord(register1) + cpu->cpuState.getWord(register2));
            break;
        case DataSize::DW:
            cpu->cpuState.writeDWordToRegisters(register1,
                                                cpu->cpuState.getDWord(register1) + cpu->cpuState.getDWord(register2));
            break;
        case DataSize::QW:
            cpu->cpuState.writeQWordToRegisters(register1,
                                                cpu->cpuState.getQWord(register1) + cpu->cpuState.getQWord(register2));
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + dataSize);
    }
}