
#include <Exceptions/ExecutionException.h>
#include "Cpu/Functors/SubFunctor.h"

cpu::SubFunctor::SubFunctor(cpu::CpuState *_cpuState) : BinaryRegisterwiseFunctor(_cpuState) {}

void cpu::SubFunctor::execute(uint8_t dataSize, uint8_t register1, uint8_t register2) {
    switch (dataSize) {
        case DataSize::B:
            executeOp<uint8_t>(register1, register2);
            break;
        case DataSize::W:
            executeOp<uint16_t>(register1, register2);
            break;
        case DataSize::DW:
            executeOp<uint32_t>(register1, register2);
            break;
        case DataSize::QW:
            executeOp<uint64_t>(register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized data size found - " + std::to_string(dataSize));
    }
}