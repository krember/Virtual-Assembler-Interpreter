//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include <Exceptions/CliException.h>

#include "Exceptions/CliException.h"

CliException::CliException(std::string message) : Exception(message) {}

CliException::CliException(VDBCommand expected, VDBCommand actual):
        Exception("Wrong command is set to be executed."
                  "Expected -> " + std::to_string(expected) + ", Actual -> " +  std::to_string(actual)){}

CliException::CliException(std::string expected, size_t actual):
Exception("Invalid argument number. "
          "Expected -> " + expected + ", Actual -> " + std::to_string(actual)){}

std::string CliException::getMessage() {
    return "CliException: " + message;
}

