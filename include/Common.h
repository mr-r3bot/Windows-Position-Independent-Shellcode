//
// Created by QUANGVO on 8/13/2024.
//

#ifndef COMMON_H
#define COMMON_H
#include <Windows.h>

#define kernel32dll_CRC32                   0x6AE69F02
#define ntdlldll_CRC32                      0x84C05E40
#define LoadLibraryA_CRC32                      0x3FC1BD8D
#define WinExec_CRC32 0x48fea11e

typedef HMODULE(WINAPI *fnLoadLibraryA)(IN LPCSTR lpLibFileName);
typedef UINT WINEXEC (
  _In_ LPCSTR lpCmdLine,
  _In_ UINT   uCmdShow
);

typedef WINEXEC* PWINEXEC;

#endif //COMMON_H
