//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Exceptions/ExecutionException.h"

ExecutionException::ExecutionException(std::string message) : Exception(message) {}

std::string ExecutionException::getMessage() {
    return "ExecutionException: " + message;
}
