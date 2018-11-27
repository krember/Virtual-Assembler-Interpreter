//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#include "Cpu/Flags.h"

cpu::Flags::Flags(uint16_t  val)
        : flags(val) {
}

bool cpu::Flags::getTrap() {
    return (flags & uint16_t(Masks::TRAP)) != 0; }

bool cpu::Flags::getCarry() {
    return (flags & uint16_t(Masks::CARRY)) != 0;
}

bool cpu::Flags::getParity() {
    return (flags & uint16_t(Masks::PARITY)) != 0;
}

bool cpu::Flags::getZero() {
    return (flags & uint16_t(Masks::ZERO)) != 0;
}

bool cpu::Flags::getSign() {
    return (flags & uint16_t(Masks::SIGN)) != 0;
}

bool cpu::Flags::getOverflow() {
    return (flags & uint16_t(Masks::OVERFLOW)) != 0;
}

uint16_t cpu::Flags::getFlags() {
    return flags;
}

void cpu::Flags::setTrap(bool trap) {
    flags = trap ? (flags | uint16_t(Masks::TRAP)) : (flags & ~uint16_t(Masks::TRAP));
}

void cpu::Flags::setCarry(bool carry) {
    flags = carry ? (flags | uint16_t(Masks::CARRY)) : (flags & ~uint16_t(Masks::CARRY));
}

void cpu::Flags::setParity(bool parity) {
    flags = parity ? (flags | uint16_t(Masks::PARITY)) : (flags & ~uint16_t(Masks::PARITY));
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