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
	vm::Memory * vMemory;

	std::string readString(FILE * file, uint32_t& address);
public:
    FileLoader(vm::Memory *_memory);

    // Loads contents of the given file to the memory.
    std::pair<uint32_t, SymbolTable> load(std::string fileName);
};

#endif //VIRTUAL_MACHINE_LOADER_H