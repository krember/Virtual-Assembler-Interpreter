//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_CPU_H
#define VIRTUAL_MACHINE_CPU_H


#include <vector>
#include "NorthBridge.h"
#include "Instruction.h"
#include "Cpu/Functors/InstructionFunctor.h"
#include "CpuState.h"

namespace cpu {
    class CPU {
        friend class SubFunctor;
        friend class SumFunctor;
    public:
        /* Constructing */
        CPU(NorthBridge *northBridge);

        /* Public interface */
        CpuState getState() const;

        void run();


    private:
        /* Private members */
        NorthBridge *vNorthBridge;
        CpuState cpuState;
        Instruction *instruction = 0; //TODO delele Instruction
        std::vector<cpu::InstructionFunctor *> instructionFunctors;

        /* Constants*/
        static const size_t ADDRESS_REGISTERS_COUNT = 16;
        static const size_t DATA_REGISTERS_COUNT = 64;
        static const std::size_t COMMAND_SIZE = 8;

        /* Private Functions*/
        void fetch();

        void decode();

        void incrementIP();

        void execute();

        void incrementIP(uint32_t offset);
    };
}

#endif //VIRTUAL_MACHINE_CPU_H
