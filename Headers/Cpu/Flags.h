//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_FLAGS_H
#define VIRTUAL_MACHINE_FLAGS_H


#include <cstdint>
#include <Config/CPUConstants.h>

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
    
        uint16_t flags;
        
    public:
        Flags(uint16_t val = 0);
    
        bool getCarry() const;
        bool getZero() const;
        bool getSign() const;
        bool getOverflow() const;

        void setCarry(bool carry );
        void setZero(bool zero);
        void setSign(bool negative);
        void setOverflow(bool overflow);
        void setFlags(uint16_t newValue); // TODO: NOTE: Modified shitty

        bool checkCondition(JumpCondition condition) const;
    };
}


#endif //VIRTUAL_MACHINE_FLAGS_H
