#include <Cpu/Functors/SumFunctor.h>
#include <Config/CPUConstants.h>
#include <Exceptions/ExecutionException.h>

cpu::SumFunctor::SumFunctor(cpu::CpuState *_cpuState) : cpuState(_cpuState) {}

void cpu::SumFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder, uint8_t register1,
                                 uint8_t register2, uint32_t literal) {
    switch (registersOrder) {
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:
            throw ExecutionException("No suitable operation found for given data types.");
        case RegisterOrder::RR:
            sum(dataSize, register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + registersOrder);
    }
}

void cpu::SumFunctor::sum(uint8_t dataSize, uint8_t register1, uint8_t register2) {
    switch (dataSize) {
        case DataSize::B:
            executeSum<uint8_t>(register1, register2);
            break;
        case DataSize::W:
            executeSum<uint16_t>(register1, register2);
            break;
        case DataSize::DW:
            executeSum<uint32_t>(register1, register2);
            break;
        case DataSize::QW:
            executeSum<uint64_t>(register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + dataSize);
    }
}

