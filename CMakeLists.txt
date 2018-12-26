cmake_minimum_required(VERSION 3.10)
project(Virtual_Machine)

set(CMAKE_CXX_STANDARD 11)

include_directories(Headers)

add_executable(Virtual_Machine
        Headers/Cpu/CPU.h
        Headers/Exceptions/Exception.h
        Headers/VM/FileLoader.h
        Headers/Cpu/Instruction.h
        Headers/Exceptions/IOException.h
        Headers/Config/LanguageConstants.h
        Headers/VM/Memory.h
        Headers/VM/VirtualMachine.h
        Sources/Cpu/CPU.cpp
        Sources/Exceptions/Exception.cpp
        Sources/VM/FileLoader.cpp
        Sources/Cpu/Instruction.cpp
        Sources/Exceptions/IOException.cpp
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
        Sources/Cpu/Functors/IncFunctor.cpp Headers/Cpu/Functors/IncFunctor.h
        Sources/VM/Debugger.cpp Headers/VM/Debugger.h
        Sources/Cpu/Functors/MovFunctor.cpp Headers/Cpu/Functors/MovFunctor.h
        Sources/Cpu/Functors/SwapFunctor.cpp Headers/Cpu/Functors/SwapFunctor.h
        Sources/Cpu/Functors/AndFunctor.cpp Headers/Cpu/Functors/AndFunctor.h
        Sources/Cpu/Functors/OrFunctor.cpp Headers/Cpu/Functors/OrFunctor.h
        Sources/Cpu/Functors/BinaryRegisterwiseFunctor.cpp Headers/Cpu/Functors/BinaryRegisterwiseFunctor.h
        Sources/Cpu/Functors/InstructionFunctor.cpp
        Sources/Cpu/Functors/XorFunctor.cpp Headers/Cpu/Functors/XorFunctor.h Sources/Cpu/Functors/NandFunctor.cpp Headers/Cpu/Functors/NandFunctor.h Sources/Cpu/Functors/NorFunctor.cpp Headers/Cpu/Functors/NorFunctor.h Sources/Cpu/Functors/NotFunctor.cpp Headers/Cpu/Functors/NotFunctor.h Sources/Cpu/Functors/PushFunctor.cpp Headers/Cpu/Functors/PushFunctor.h Sources/Cpu/Functors/PopFunctor.cpp Headers/Cpu/Functors/PopFunctor.h Sources/Cpu/Functors/CallAddressFunctor.cpp Headers/Cpu/Functors/CallAddressFunctor.h Sources/Cpu/Functors/BreakFunctor.cpp Headers/Cpu/Functors/BreakFunctor.h
        Sources/Cpu/Functors/RetFunctor.cpp Headers/Cpu/Functors/RetFunctor.h Sources/Cpu/Functors/ExitFunctor.cpp Headers/Cpu/Functors/ExitFunctor.h
        "Headers/VdbCli/Tokenizer.h" "Sources/VdbCli/Tokenizer.cpp" "Headers/VdbCli/Definitions.h" "Headers/VdbCli/Parser.h" "Sources/VdbCli/Parser.cpp" "Headers/VdbCli/Commands/Command.h" "Headers/VdbCli/Utils.h" "Sources/VdbCli/Utils.cpp" "Sources/VdbCli/Commands/SetBreakpointCommand.cpp" "Headers/VdbCli/Commands/SetBreakpointCommand.h" "Sources/VdbCli/Commands/RemoveBreakpointCommand.cpp" "Headers/VdbCli/Commands/RemoveBreakpointCommand.h" "Sources/VdbCli/Commands/ShowStackTraceCommand.cpp" "Headers/VdbCli/Commands/ShowStackTraceCommand.h" "Sources/VdbCli/Commands/StepInCommand.cpp" "Headers/VdbCli/Commands/StepInCommand.h" "Sources/VdbCli/Commands/StepOverCommand.cpp" "Headers/VdbCli/Commands/StepOverCommand.h" "Sources/VdbCli/Commands/ContinueCommand.cpp" "Headers/VdbCli/Commands/ContinueCommand.h" "Sources/VdbCli/Commands/PrintRegisterCommand.cpp" "Headers/VdbCli/Commands/PrintRegisterCommand.h" "Sources/VdbCli/Commands/CommandWrapper.cpp" "Headers/VdbCli/Commands/CommandWrapper.h" Sources/Exceptions/CliException.cpp Headers/Exceptions/CliException.h Sources/VdbCli/VdbCliCore.cpp Headers/VdbCli/VdbCliCore.h Sources/Cpu/Functors/LoadFunctor.cpp Headers/Cpu/Functors/LoadFunctor.h Sources/Cpu/Functors/StoreFunctor.cpp Headers/Cpu/Functors/StoreFunctor.h Headers/VM/Logging/Logger.h Sources/VM/Logging/ConsoleLogger.cpp Headers/VM/Logging/ConsoleLogger.h Sources/VM/Logging/Logging.cpp Headers/VM/Logging/Logging.h Headers/VM/Logging/LoggingSeverity.h Sources/VdbCli/VdbCli.cpp Headers/VdbCli/VdbCli.h)