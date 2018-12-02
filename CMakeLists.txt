cmake_minimum_required(VERSION 3.10)
project(Virtual_Machine)

set(CMAKE_CXX_STANDARD 11)

include_directories(Headers)

add_executable(Virtual_Machine
        Headers/BinaryUtils.h
        Headers/Console.h
        Headers/Cpu/CPU.h
        Headers/Exceptions/Exception.h
        Headers/FileLoader.h
        Headers/Instruction.h
        Headers/Exceptions/IOException.h
        Headers/Config/LanguageConstants.h
        Headers/Memory.h
        Headers/StructuredFile.h
        Headers/VirtualMachine.h
        Sources/BinaryUtils.cpp
        Sources/Console.cpp
        Sources/Cpu/CPU.cpp
        Sources/Exceptions/Exception.cpp
        Sources/FileLoader.cpp
        Sources/Instruction.cpp
        Sources/Exceptions/IOException.cpp
        Sources/StructuredFile.cpp
        Sources/VirtualMachine.cpp
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
        Sources/Memory.cpp
        Headers/Config/VMConstants.h
        Headers/ObjectFile/SymbolTable.h Sources/ObjectFile/SymbolTable.cpp
        Sources/Cpu/Functors/MulFunctor.cpp Headers/Cpu/Functors/MulFunctor.h
        Sources/Cpu/Functors/DivFunctor.cpp Headers/Cpu/Functors/DivFunctor.h
        Sources/Cpu/Functors/AssignFunctor.cpp Headers/Cpu/Functors/AssignFunctor.h)
