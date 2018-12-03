//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_FLAGS_H
#define VIRTUAL_MACHINE_FLAGS_H


#include <cstdint>
namespace cpu {
    class Flags {
    private:
        enum Masks
        {
            CARRY = 0x0001,
            ZERO = 0x0001 << 6,
            SIGN = 0x0001 << 7,
            OVERFLOW = 0x0001 << 11
        };
    
        uint16_t flags; //TODO : make flags uint64_t or change in the Functors
        
    public:
        Flags(uint16_t val = 0);
    
        bool getCarry();
        bool getZero();
        bool getSign();
        bool getOverflow();
        uint16_t getFlags(); // TODO: NOTE: Modified shitty
    
        void setCarry(bool carry );
        void setZero(bool zero);
        void setSign(bool negative);
        void setOverflow(bool overflow);
        void setFlags(uint16_t newValue); // TODO: NOTE: Modified shitty

        //TODO: JE here from shitty
    };
}


#endif //VIRTUAL_MACHINE_FLAGS_H
