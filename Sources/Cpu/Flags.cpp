//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Flags.h"

cpu::Flags::Flags(uint16_t val)
        : flags(val) {
}

bool cpu::Flags::getCarry() const {
    return (flags & uint16_t(Masks::CARRY)) != 0;
}

bool cpu::Flags::getZero() const {
    return (flags & uint16_t(Masks::ZERO)) != 0;
}

bool cpu::Flags::getSign() const {
    return (flags & uint16_t(Masks::SIGN)) != 0;
}

bool cpu::Flags::getOverflow() const {
    return (flags & uint16_t(Masks::OVERFLOW)) != 0;
}

void cpu::Flags::setCarry(bool carry) {
    flags = carry ? (flags | uint16_t(Masks::CARRY)) : (flags & ~uint16_t(Masks::CARRY));
}

void cpu::Flags::setZero(bool zero) {
    flags = zero ? (flags | uint16_t(Masks::ZERO)) : (flags & ~uint16_t(Masks::ZERO));
}

void cpu::Flags::setSign(bool negative) {
    flags = negative ? (flags | uint16_t(Masks::SIGN)) : (flags & ~uint16_t(Masks::SIGN));
}

void cpu::Flags::setOverflow(bool overflow) {
    flags = overflow ? (flags | uint16_t(Masks::OVERFLOW)) : (flags & ~uint16_t(Masks::OVERFLOW));
}

void cpu::Flags::setFlags(uint16_t newValue) {
    flags = newValue;
}

bool cpu::Flags::checkCondition(cpu::JumpCondition condition) const {
    switch (condition) {
        case JumpCondition::JE:
            if(!getZero())
                return false;
        case JumpCondition::JNE:
            if(getZero())
                return false;
        case JumpCondition::JA:
            if(getCarry() || getZero())
                return false;
        case JumpCondition::JAE:
            if(getCarry())
                return false;
        case JumpCondition::JB:
            if(!getCarry())
                return false;
        case JumpCondition::JBE:
            if(!getZero() && !getCarry())
                return false;
        case JumpCondition::JG:
            if(getZero() || getSign() != getOverflow())
                return false;
        case JumpCondition::JGE:
            if(getSign() != getOverflow())
                return false;
        case JumpCondition::JL:
            if(getSign() == getOverflow())
                return false;
        case JumpCondition::JLE:
            if(!getZero() && getSign() == getOverflow())
                return false;
        case JumpCondition::JO:
            if(!getOverflow())
                return false;
        case JumpCondition::JNO:
            if(getOverflow())
                return false;
        case JumpCondition::JS:
            if(!getSign())
                return false;
        case JumpCondition::JNS:
            if(getSign())
                return false;
    }
    return true;
}
