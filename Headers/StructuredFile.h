//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_STRUCTUREDFILE_H
#define VIRTUAL_MACHINE_STRUCTUREDFILE_H

#include <string>
#include <vector>

class StructuredFile {
private:
    /* Private members */
    std::vector<std::string> codeSection;
public:
    /* Constructing */
    StructuredFile();
    StructuredFile(std::vector<std::string> codeSection);

    /* Public interface */
    void addOperation(std::string operation); // Adds new operation to the code section of the file
    bool hasLine(uint32_t line); // Checks whether there is an operation available at the given line
    std::string getOperation(uint32_t line); // Gets operations at the given line
};


#endif //VIRTUAL_MACHINE_STRUCTUREDFILE_H
