//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_CPU_H
#define VIRTUAL_MACHINE_CPU_H

#include <vector>
#include "VM/Memory.h"
#include "Instruction.h"
#include "Cpu/Functors/InstructionFunctor.h"
#include "CpuState.h"

namespace cpu {
    class CPU {
    public:
        /* Constructing */
        explicit CPU(vm::Memory *_memory);

        /* Public interface */
        const CpuState& state() const;

        void run();
        void step();

    private:
        /* Private members */
        vm::Memory *vMemory;
        CpuState cpuState;
        std::vector<cpu::InstructionFunctor *> instructionFunctors;

        /* Private Functions*/
        void fetch();
        void decode(Instruction * instruction);
        void incrementIP();
        void execute(Instruction * instruction);
        void initFunctors(std::vector<cpu::InstructionFunctor*> &_instructionFunctors);
    };
}

#endif //VIRTUAL_MACHINE_CPU_H
