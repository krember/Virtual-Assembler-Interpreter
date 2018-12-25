//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_CONSOLELOGGER_H
#define VIRTUAL_MACHINE_CONSOLELOGGER_H


#include "Logger.h"

class ConsoleLogger: public Logger {
public:
    static ConsoleLogger* getInstance();
    void out(std::string message);
    void log(std::string message, LoggingSeverity loggingSeverity) override;
private:
    ConsoleLogger();

    static ConsoleLogger* consoleLogger;
    void info(std::string message) override;
    void warning(std::string message) override;
    void severe(std::string message) override;
};


#endif //VIRTUAL_MACHINE_CONSOLELOGGER_H
