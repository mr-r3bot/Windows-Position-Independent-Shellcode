//
// Created by QUANGVO on 8/13/2024.
//

#ifndef UTILS_H
#define UTILS_H


UINT32 CRC32B(LPCSTR cString);
#define CRCHASH(STR)    ( CRC32B( (LPCSTR)STR ))
#define memcpy __builtin_memcpy
SIZE_T StringLengthA(_In_ LPCSTR String);
SIZE_T StringLengthW(_In_ LPCWSTR String);

HMODULE GetModuleHandleH(IN UINT32 uModuleHash);
FARPROC GetProcAddressH(IN HMODULE hModule, IN UINT32 uApiHash);
#endif //UTILS_H
