//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_VDBCLI_H
#define VIRTUAL_MACHINE_VDBCLI_H


#include <VM/VirtualMachine.h>
#include "VdbCliCore.h"

class VdbCli {
private:
    vm::VirtualMachine* virtualMachine;
    VdbCliCore* cliCore;

public:
    VdbCli();
    virtual ~VdbCli();

    void run(std::string filename);
    void loop();
};


#endif //VIRTUAL_MACHINE_VDBCLI_H
