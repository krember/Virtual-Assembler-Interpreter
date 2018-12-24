//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_CLIEXCEPTION_H
#define VIRTUAL_MACHINE_CLIEXCEPTION_H

#include <VdbCli/Commands.h>
#include "Exception.h"

class CliException :
        public Exception {
public:
    CliException(std::string message);
    CliException(VDBCommand expected, VDBCommand actual);
    CliException(std::string expected, size_t actual);
    virtual std::string getMessage() override;
};

#endif //VIRTUAL_MACHINE_CLIEXCEPTION_H
