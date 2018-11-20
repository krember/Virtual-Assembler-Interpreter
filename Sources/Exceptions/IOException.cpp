//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include "Exceptions/IOException.h"

IOException::IOException(std::string message) : Exception(message) {}

std::string IOException::getMessage() {
	return "IOException: " + message;
}
