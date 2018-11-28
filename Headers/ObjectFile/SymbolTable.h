
#ifndef COMPILER_NAREK_HOVHANNISYAN_SYMBOLTABLE_H
#define COMPILER_NAREK_HOVHANNISYAN_SYMBOLTABLE_H

#include <string>
#include <map>

class SymbolTable {
private:
    std::map<std::string, int> m_table;

public:
    SymbolTable();

    void add(std::string name, int offset);
    int getOffset(std::string name);
    bool exists(std::string name);
    long size();
    const std::map<std::string, int>& getTable();
};


#endif //COMPILER_NAREK_HOVHANNISYAN_SYMBOLTABLE_H
