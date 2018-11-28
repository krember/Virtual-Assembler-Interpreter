
#include "ObjectFile/Header.h"

Header::Header(uint32_t symbolTableOffset, uint32_t dataSectionOffset, uint32_t codeSectionOffset) : m_symbolTableOffset(
        symbolTableOffset), m_dataSectionOffset(dataSectionOffset), m_codeSectionOffset(codeSectionOffset) {}

Header::Header() {}

uint32_t Header::getSymbolTableOffset() const {
    return m_symbolTableOffset;
}

void Header::setSymbolTableOffset(uint32_t symbolTableOffset) {
    Header::m_symbolTableOffset = symbolTableOffset;
}

uint32_t Header::getDataSectionOffset() const {
    return m_dataSectionOffset;
}

void Header::setDataSectionOffset(uint32_t dataSectionOffset) {
    Header::m_dataSectionOffset = dataSectionOffset;
}

uint32_t Header::getCodeSectionOffset() const {
    return m_codeSectionOffset;
}

void Header::setCodeSectionOffset(uint32_t codeSectionOffset) {
    Header::m_codeSectionOffset = codeSectionOffset;
}