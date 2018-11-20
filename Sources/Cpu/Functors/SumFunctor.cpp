#include <Cpu/Functors/SumFunctor.h>
#include <Cpu/CPUConstants.h>
#include <Exceptions/ExecutionException.h>

cpu::SumFunctor::SumFunctor(cpu::CPU* _cpu): cpu(_cpu){}

void cpu::SumFunctor::operator()(uint8_t jumpExtension, uint8_t dataSize, uint8_t registersOrder, uint8_t register1,
                                 uint8_t register2, uint32_t literal) {
    switch (registersOrder){
        case RegisterOrder::AA:
        case RegisterOrder::AR:
        case RegisterOrder::RA:{
            throw ExecutionException("No suitable operation found for given data types.");
        }
        case RegisterOrder::RR:
            sum(dataSize, register1, register2);
            break;
        default:
            throw ExecutionException("Unrecognized register types found - " + registersOrder);
    }
}

void cpu::SumFunctor::sum(uint8_t dataSize, uint8_t register1, uint8_t register2) {
    switch (dataSize) {
        case DataSize::B: {
            cpu->cpuState.writeByteToRegisters(register1,
                                               cpu->cpuState.generalPurposeRegisters[register1] + cpu->cpuState.generalPurposeRegisters[register2]);
        }
        case DataSize::W: {
            cpu->cpuState.writeWordToRegisters(register1,
                                               cpu->cpuState.generalPurposeRegisters[register1] + cpu->cpuState.generalPurposeRegisters[register2]);
        }
        case DataSize::DW: {
            cpu->cpuState.writeDWordToRegisters(register1,
                                                cpu->cpuState.generalPurposeRegisters[register1] + cpu->cpuState.generalPurposeRegisters[register2]);
        }
        case DataSize::QW: {
            cpu->cpuState.writeQWordToRegisters(register1,
                                                cpu->cpuState.generalPurposeRegisters[register1] + cpu->cpuState.generalPurposeRegisters[register2]);
        }
        default: {
            throw ExecutionException("Unrecognized data size found - " + dataSize);
        }
    }
}


