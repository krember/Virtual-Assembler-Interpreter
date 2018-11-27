
#include <Exceptions/ExecutionException.h>
#include "Cpu/Functors/SubFunctor.h"

cpu::SubFunctor::SubFunctor(cpu::CpuState *_cpuState) : cpuState(_cpuState) {}

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
            executeSub<uint8_t>(register1, register2);
            break;
        case DataSize::W:
            executeSub<uint16_t>(register1, register2);
            break;
        case DataSize::DW:
            executeSub<uint32_t>(register1, register2);
            break;
        case DataSize::QW:
            executeSub<uint64_t>(register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + dataSize);
    }
}
