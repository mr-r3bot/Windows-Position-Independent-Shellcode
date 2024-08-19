cmake_minimum_required(VERSION 3.28)
project(Windows_PIC C ASM_NASM)

set(CMAKE_C_STANDARD 11)
#set( CMAKE_C_COMPILER "x86_64-w64-mingw32-gcc" )
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# Debug
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/$<CONFIG>")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/$<CONFIG>")
# Assenmbly
set(CMAKE_ASM_NASM_OBJECT_FORMAT win64)
# Sources
set (SOURCE_FILES
        src/main.c
        src/Util/Ldr.c
        include/Utils.h
        include/Common.h
        src/Util/Util.c
        src/pic.asm
)
# CFFLAGS
set(CFLAGS "-Os -fno-asynchronous-unwind-tables -nostdlib \
-fno-ident -fpack-struct=8 -falign-functions=1 \
-s -ffunction-sections -falign-jumps=1 -w \
-falign-labels=1 -fPIC \
-Wl,-T${CMAKE_CURRENT_LIST_DIR}/scripts/Linker.ld \
-Wl,-s,--no-seh,--enable-stdcall-fixup \
-masm=intel -fpermissive -mrdrnd"
    )

# set(CMAKE_ASM_NASM_COMPILE_OBJECT "${CMAKE_ASM_NASM_COMPILER} -f win64  ${CMAKE_CURRENT_LIST_DIR}/src/pic.asm -o ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/pic.o" )
set(CMAKE_C_FLAGS  ${CFLAGS})

# Building
add_executable(Windows_PIC ${SOURCE_FILES})
target_include_directories(Windows_PIC PUBLIC "/include"
        PUBLIC "/src/*")