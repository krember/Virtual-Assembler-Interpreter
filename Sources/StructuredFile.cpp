//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include "../Headers/StructuredFile.h"

StructuredFile::StructuredFile() : codeSection() {

}

StructuredFile::StructuredFile(std::vector<std::string> code) :codeSection(code) {

}

void StructuredFile::addOperation(std::string operation) {
    codeSection.push_back(operation);
}

bool StructuredFile::hasLine(uint32_t line) {
    return codeSection.size() > line;
}


std::string StructuredFile::getOperation(uint32_t line) {
    return codeSection.at(line);
}