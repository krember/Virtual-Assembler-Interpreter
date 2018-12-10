//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_MEMORY_H
#define VIRTUAL_MACHINE_MEMORY_H

#include <vector>

namespace vm {
    class Memory {
    private:
        std::vector<uint8_t> data;
        size_t memorySize;
        size_t stackSize;
    public:
        Memory(size_t memorySize, size_t stackSize);

        template<typename valueType>
        valueType read(uint32_t address);

        template<typename valueType>
        void write(uint32_t address, valueType data);

        size_t getMemorySize() const;
        size_t getStackSize() const;
    };

    template<typename valueType>
    valueType Memory::read(uint32_t address) {
        return *reinterpret_cast<valueType *>(data.data() + address);
    }

    template<typename valueType>
    void Memory::write(uint32_t address, valueType value) {
        *reinterpret_cast<valueType *>(data.data() + address) = value;
    }
}

#endif //VIRTUAL_MACHINE_MEMORY_H
