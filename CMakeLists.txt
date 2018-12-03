cmake_minimum_required(VERSION 3.10)
project(Virtual_Machine)

set(CMAKE_CXX_STANDARD 11)

include_directories(Headers)

add_executable(Virtual_Machine
        Headers/BinaryUtils.h
        Headers/Cpu/CPU.h
        Headers/Exceptions/Exception.h
        Headers/VM/FileLoader.h
        Headers/Cpu/Instruction.h
        Headers/Exceptions/IOException.h
        Headers/Config/LanguageConstants.h
        Headers/VM/Memory.h
        Headers/StructuredFile.h
        Headers/VM/VirtualMachine.h
        Sources/BinaryUtils.cpp
        Sources/Cpu/CPU.cpp
        Sources/Exceptions/Exception.cpp
        Sources/VM/FileLoader.cpp
        Sources/Cpu/Instruction.cpp
        Sources/Exceptions/IOException.cpp
        Sources/StructuredFile.cpp
        Sources/VM/VirtualMachine.cpp
        main.cpp Headers/Config/CPUConstants.h
        Headers/Cpu/Functors/InstructionFunctor.h
        Sources/Cpu/Functors/SubFunctor.cpp
        Headers/Cpu/Functors/SubFunctor.h
        Sources/Cpu/Functors/SumFunctor.cpp
        Headers/Cpu/Functors/SumFunctor.h
        Sources/Cpu/CpuState.cpp
        Headers/Cpu/CpuState.h
        Sources/Exceptions/ExecutionException.cpp
        Headers/Exceptions/ExecutionException.h
        Sources/Cpu/Flags.cpp Headers/Cpu/Flags.h
        Headers/ObjectFile/Header.h Sources/ObjectFile/Header.cpp
        Headers/ObjectFile/ObjectFile.h Sources/ObjectFile/ObjectFile.cpp
        Headers/ObjectFile/SymbolTable.h Sources/ObjectFile/SymbolTable.cpp
        Sources/VM/Memory.cpp
        Headers/Config/VMConstants.h
        Headers/ObjectFile/SymbolTable.h Sources/ObjectFile/SymbolTable.cpp
        Sources/Cpu/Functors/MulFunctor.cpp Headers/Cpu/Functors/MulFunctor.h
        Sources/Cpu/Functors/DivFunctor.cpp Headers/Cpu/Functors/DivFunctor.h
        Sources/Cpu/Functors/AssignFunctor.cpp Headers/Cpu/Functors/AssignFunctor.h
        Sources/Cpu/Functors/JumpFunctor.cpp Headers/Cpu/Functors/JumpFunctor.h
        Sources/Cpu/Functors/DecFunctor.cpp Headers/Cpu/Functors/DecFunctor.h
        Sources/Cpu/Functors/AssignFunctor.cpp Headers/Cpu/Functors/AssignFunctor.h
        Sources/Cpu/Functors/NopFunctor.cpp Headers/Cpu/Functors/NopFunctor.h
        Sources/Cpu/Functors/IncFunctor.cpp Headers/Cpu/Functors/IncFunctor.h Sources/VM/Debugger.cpp Headers/VM/Debugger.h Sources/Cpu/Functors/MovFunctor.cpp Headers/Cpu/Functors/MovFunctor.h Sources/Cpu/Functors/SwapFunctor.cpp Headers/Cpu/Functors/SwapFunctor.h Sources/Cpu/Functors/AndFunctor.cpp Headers/Cpu/Functors/AndFunctor.h Sources/Cpu/Functors/OrFunctor.cpp Headers/Cpu/Functors/OrFunctor.h Sources/Cpu/Functors/BinaryRegisterwiseFunctor.cpp Headers/Cpu/Functors/BinaryRegisterwiseFunctor.h Sources/Cpu/Functors/InstructionFunctor.cpp Sources/Cpu/Functors/XorFunctor.cpp Headers/Cpu/Functors/XorFunctor.h Sources/Cpu/Functors/NandFunctor.cpp Headers/Cpu/Functors/NandFunctor.h Sources/Cpu/Functors/NorFunctor.cpp Headers/Cpu/Functors/NorFunctor.h Sources/Cpu/Functors/NotFunctor.cpp Headers/Cpu/Functors/NotFunctor.h)
