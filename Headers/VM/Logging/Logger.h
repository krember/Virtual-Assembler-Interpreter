//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_LOGGER_H
#define VIRTUAL_MACHINE_LOGGER_H

#include <string>
#include "LoggingSeverity.h"

class Logger {
public:
    virtual void log(std::string message, LoggingSeverity loggingSeverity) = 0;

protected:
    virtual void info(std::string message) = 0;
    virtual void warning(std::string message) = 0;
    virtual void severe(std::string message) = 0;
};

#endif //VIRTUAL_MACHINE_LOGGER_H
