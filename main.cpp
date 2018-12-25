#include <iostream>
#include <cstring>
#include <VdbCli/VdbCli.h>
#include "VM/VirtualMachine.h"

int main() {

//    std::vector<uint8_t> ram;
//    ram.push_back(0);
//    ram.push_back(0);
//    ram.push_back(02342);
//    ram.push_back(102);
//    ram.push_back(1);
//    ram.push_back(123);
//    ram.push_back(133);
//    ram.push_back(0);
//    ram.push_back(14);
//    ram.push_back(0);
//    ram.push_back(0);
//    ram.push_back(1);
//
//    std::cout<< (int)ram.at(5) <<std::endl;
//
//    *reinterpret_cast<uint32_t *>(ram.data() + 5) = 1;
//
//    std::cout<< (int)ram.at(5) <<std::endl;
//
//    //TEST
//
//    cpu::CpuState cpuState;
//    cpu::SubFunctor functor(&cpuState);
//
//    functor(1,0,3,0,0,1);

    vm::VirtualMachine *vm = new vm::VirtualMachine();
    vm -> debug("inputCompiler.exe");

    VdbCli vdbcli(vm->vdb);

    vdbcli.execute("step_in");
    vdbcli.execute("print R0 -s DW");
    std::cout << std::endl;
    vdbcli.execute("step_in");
    vdbcli.execute("print A2 -s DW");
    vdbcli.execute("step_in");
    vdbcli.execute("print R0 -s DW");

    return 0;
}