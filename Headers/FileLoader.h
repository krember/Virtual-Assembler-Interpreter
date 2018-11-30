//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_LOADER_H
#define VIRTUAL_MACHINE_LOADER_H

#include <string>
#include <fstream>
#include <ObjectFile/ObjectFile.h>
#include "ObjectFile/ObjectFile.h"
#include "Exceptions/IOException.h"
#include "Memory.h"

class FileLoader {
private:
	Memory * vMemory;

public:
    FileLoader(Memory *_memory);

    // Reads and parses contents of the given file. Should throw exceptions.
    void load(std::string fileName);
};

#endif //VIRTUAL_MACHINE_LOADER_H