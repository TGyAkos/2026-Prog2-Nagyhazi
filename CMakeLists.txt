cmake_minimum_required(VERSION 4.1)
project(titkosito)

set(CMAKE_CXX_STANDARD 20)

add_executable(titkosito main.cpp
        MessageFile.cpp
        MessageFile.h
        CipherFile.cpp
        CipherFile.h
        Registrar.h
        CipherList.cpp
        CipherList.h
        CipherFactory.cpp
        CipherFactory.h
        Cipher.h
        CaesarCipher.cpp
        CaesarCipher.h
        MyCipher.cpp
        MyCipher.h
        TranspositionCipher.cpp
        TranspositionCipher.h
        StringFuncs.cpp
        StringFuncs.h
        memtrace.cpp
        memtrace.h
        gtest_lite.h
        test.cpp
        test.h
)

target_compile_options(titkosito PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wdeprecated -pedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

target_compile_definitions(titkosito PRIVATE MEMTRACE)

# Equivalent of -g only for Debug builds (GNU/Clang)
target_compile_options(titkosito PRIVATE
        $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:GNU,Clang>>:-g>
)

