//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "VM/Logging/Logging.h"

std::vector<Logger*> Logging::loggers;

void Logging::registerLogger(Logger *logger) {
    loggers.push_back(logger);
}

void Logging::logToAllLoggers(std::string message, LoggingSeverity loggingSeverity) {
    for(Logger* logger : loggers){
        logger->log(message,loggingSeverity);
    }
}
