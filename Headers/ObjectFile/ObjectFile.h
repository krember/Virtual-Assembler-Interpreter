
#ifndef COMPILER_NAREK_HOVHANNISYAN_OBJECTFILE_H
#define COMPILER_NAREK_HOVHANNISYAN_OBJECTFILE_H

#include <vector>
#include "Header.h"
#include "SymbolTable.h"

class ObjectFile {
private:
    Header m_header;
    SymbolTable m_symbolTable;
    //TODO: DataSection
    std::vector<uint64_t> m_codeSection;

public:
    ObjectFile();

    const Header &getHeader() const;
    void setHeader(const Header &m_header);
    SymbolTable *getSymbolTable();
    long sizeOfCodeSection();
    void generateHeader();
};


#endif //COMPILER_NAREK_HOVHANNISYAN_OBJECTFILE_H
