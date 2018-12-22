//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include "VM/FileLoader.h"

FileLoader::FileLoader(vm::Memory *_memory) : vMemory(_memory) {

}

std::pair<uint32_t, SymbolTable> FileLoader::load(std::string fileName) {
    FILE * file = std::fopen(fileName.c_str(), "rb");
    if(file == nullptr) {
        throw IOException("Could not open file with name : " + fileName);
    }
    uint32_t symbolTableOffset;
    uint32_t dataSectionOffset;
    uint32_t codeSectionOffset;
    uint32_t reallocationTableOffset;
    std::fread(&symbolTableOffset, sizeof(uint32_t), 1, file);
    std::fread(&dataSectionOffset, sizeof(uint32_t), 1, file);
    std::fread(&codeSectionOffset, sizeof(uint32_t), 1, file);
    std::fread(&reallocationTableOffset, sizeof(uint32_t), 1, file);

    uint32_t address = 16;
    uint32_t inMemoryAddress = 0;
    uint32_t codeSectionOffsetInMemory = 0;

    uint64_t command;

    SymbolTable symbolTable;
    while(address >= symbolTableOffset && address < dataSectionOffset) {
        std::string name = readString(file, address);
        uint32_t offset;
        std::fread(&offset, sizeof(uint32_t), 1, file);
        address += 4;
        symbolTable.add(name, offset);
    }

    while(address >= dataSectionOffset && address < codeSectionOffset) {
        std::fread(&command, sizeof(uint64_t), 1, file);  // TODO : This returns "DWORD a 4". Is it right? How should we handle it?
        address += 8;
    }

    while(address >= codeSectionOffset && address < reallocationTableOffset) {
        std::fread(&command, sizeof(uint64_t), 1, file);
        vMemory->write<uint64_t>(inMemoryAddress, command);
        address += 8;
        inMemoryAddress += 8;
    }
    std::fclose(file);

    return std::make_pair(codeSectionOffsetInMemory, symbolTable);
}

std::string FileLoader::readString(FILE *file, uint32_t &address) {
    if (file == nullptr)
        throw IOException("Cannot connect to input file");
    std::string result;
    unsigned char ch;
    while ((ch = std::fgetc(file)) != EOF  && ch != '\0') {
        result += ch;
        address += 1;
    }
    address += 1;
    return result;
}