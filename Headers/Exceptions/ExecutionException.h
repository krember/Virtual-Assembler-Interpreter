//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_CPUEXCEPTION_H
#define VIRTUAL_MACHINE_CPUEXCEPTION_H

#include "Exception.h"

class ExecutionException :
        public Exception
{
public:
    ExecutionException(std::string message);
    virtual std::string getMessage() override;
};

#endif //VIRTUAL_MACHINE_CPUEXCEPTION_H
