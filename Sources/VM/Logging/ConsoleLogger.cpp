//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <VM/Logging/ConsoleLogger.h>
#include <iostream>

#include "VM/Logging/ConsoleLogger.h"

ConsoleLogger *ConsoleLogger::consoleLogger = nullptr;

ConsoleLogger::ConsoleLogger() = default;

ConsoleLogger *ConsoleLogger::getInstance() {
    if (consoleLogger == nullptr) {
        consoleLogger = new ConsoleLogger();
    }
    return consoleLogger;
}

void ConsoleLogger::log(std::string message, LoggingSeverity loggingSeverity) {
    switch (loggingSeverity) {
        case INFO: {
            info(message);
            break;
        }
        case WARNING: {
            warning(message);
            break;
        }
        case SEVERE: {
            severe(message);
            break;
        }
        default: {
            // No matching Severity
        }
    }
}

void ConsoleLogger::info(std::string message) {
    std::cout << " INFO : " << message << std::endl;
}

void ConsoleLogger::warning(std::string message) {
    std::cout << " WARNING : " << message << std::endl;
}

void ConsoleLogger::severe(std::string message) {
    std::cout << " SEVERE : " << message << std::endl;
}

void ConsoleLogger::out(std::string message) {
    std::cout << message;
}
