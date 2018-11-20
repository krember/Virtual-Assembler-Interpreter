//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_LOADER_H
#define VIRTUAL_MACHINE_LOADER_H

#include <string>
#include <fstream>
#include "StructuredFile.h"
#include "Exceptions/IOException.h"

class FileLoader {
private:
	static const std::string CODE;

public:
    FileLoader();

    // Reads and parses contents of the given file. Should throw exceptions.
    StructuredFile load(std::string fileName);
};


#endif //VIRTUAL_MACHINE_LOADER_H
