
#include <Cpu/CPU.h>
#include <Cpu/CPUConstants.h>
#include "ObjectFile/ObjectFile.h"

ObjectFile::ObjectFile() {

}

const Header &ObjectFile::getHeader() const {
    return m_header;
}

void ObjectFile::setHeader(const Header &m_header) {
    ObjectFile::m_header = m_header;
}

SymbolTable *ObjectFile::getSymbolTable() {
    SymbolTable *retVal = &m_symbolTable;
    return retVal;
}

void ObjectFile::generateHeader() {
    m_header.setSymbolTableOffset(3 * 4);
    m_header.setCodeSectionOffset(m_header.getSymbolTableOffset() + m_symbolTable.size() * 12);  //TODO : just to execute code add data section later
//    m_header.setCodeSectionOffset(m_header.getDataSectionOffset() + m_dataSection->size() * 8);
}

long ObjectFile::sizeOfCodeSection() {
    long size = 0;
    for(auto const &code : m_codeSection) {
        size += m_codeSection.size() * COMMAND_SIZE;
    }
    return size;
}