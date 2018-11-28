
#include <ObjectFile/SymbolTable.h>

SymbolTable::SymbolTable() {
    m_table.insert(std::pair<std::string, int>("R0", 0));
    m_table.insert(std::pair<std::string, int>("R1", 1));
    m_table.insert(std::pair<std::string, int>("R2", 2));
    m_table.insert(std::pair<std::string, int>("R3", 3));
    m_table.insert(std::pair<std::string, int>("R4", 4));
    m_table.insert(std::pair<std::string, int>("R5", 5));
    m_table.insert(std::pair<std::string, int>("R6", 6));
    m_table.insert(std::pair<std::string, int>("R7", 7));
    m_table.insert(std::pair<std::string, int>("R8", 8));
    m_table.insert(std::pair<std::string, int>("R9", 9));
    m_table.insert(std::pair<std::string, int>("R10", 10));
    m_table.insert(std::pair<std::string, int>("R11", 11));
    m_table.insert(std::pair<std::string, int>("R12", 12));
    m_table.insert(std::pair<std::string, int>("R13", 13));
    m_table.insert(std::pair<std::string, int>("R14", 14));
    m_table.insert(std::pair<std::string, int>("R15", 15));
    m_table.insert(std::pair<std::string, int>("IP", 0));
    m_table.insert(std::pair<std::string, int>("TR", 1));
    m_table.insert(std::pair<std::string, int>("SP", 2));
    m_table.insert(std::pair<std::string, int>("SF", 3));
    m_table.insert(std::pair<std::string, int>("A1", 1));
    m_table.insert(std::pair<std::string, int>("A2", 2));
    m_table.insert(std::pair<std::string, int>("A3", 3));
    m_table.insert(std::pair<std::string, int>("A4", 4));
}

void SymbolTable::add(std::string name, int offset) {
    m_table.insert(std::pair<std::string, int>(name, offset));
}

int SymbolTable::getOffset(std::string name) {
    return m_table[name];
}

bool SymbolTable::exists(std::string name) {
    return m_table.find(name) != m_table.end();
}


long SymbolTable::size() {
    return m_table.size();
}

const std::map<std::string, int> & SymbolTable::getTable() {
    return m_table;
}
