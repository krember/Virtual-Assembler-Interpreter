
#ifndef COMPILER_NAREK_HOVHANNISYAN_HEADER_H
#define COMPILER_NAREK_HOVHANNISYAN_HEADER_H


#include <cstdint>

class Header {
private:
    uint32_t m_symbolTableOffset;
    uint32_t m_dataSectionOffset;
    uint32_t m_codeSectionOffset;

public:
    Header();

    Header(uint32_t symbolTableOffset, uint32_t dataSectionOffset, uint32_t codeSectionOffset);

    uint32_t getSymbolTableOffset() const;
    void setSymbolTableOffset(uint32_t symbolTableOffset);
    uint32_t getDataSectionOffset() const;
    void setDataSectionOffset(uint32_t dataSectionOffset);
    uint32_t getCodeSectionOffset() const;
    void setCodeSectionOffset(uint32_t codeSectionOffset);
};


#endif //COMPILER_NAREK_HOVHANNISYAN_HEADER_H
