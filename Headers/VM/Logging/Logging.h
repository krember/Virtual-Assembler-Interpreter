//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_LOGGING_H
#define VIRTUAL_MACHINE_LOGGING_H


#include <vector>
#include "Logger.h"

class Logging {
public:
    static void registerLogger(Logger *logger);
    static void logToAllLoggers(std::string message, LoggingSeverity loggingSeverity);
private:
   static std::vector<Logger*> loggers;
};


#endif //VIRTUAL_MACHINE_LOGGING_H
