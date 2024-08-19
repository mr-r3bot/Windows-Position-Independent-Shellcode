//
// Created by QUANGVO on 8/14/2024.
//

#include <Windows.h>

#define CRC_POLYNOMIAL                      0xEDB88320

UINT32 CRC32B(LPCSTR cString)
{

    UINT32      uMask = 0x00,
        uHash = 0xFFFFFFFF;
    INT         i = 0x00;

    while (cString[i] != 0) {

        uHash = uHash ^ (UINT32)cString[i];

        for (int ii = 0; ii < 8; ii++) {

            uMask = -1 * (uHash & 1);
            uHash = (uHash >> 1) ^ (CRC_POLYNOMIAL & uMask);
        }

        i++;
    }

    return ~uHash;
}

SIZE_T StringLengthA(_In_ LPCSTR String)
{
    LPCSTR String2;

    for (String2 = String; *String2; ++String2);

    return (String2 - String);
}

SIZE_T StringLengthW(_In_ LPCWSTR String)
{
    LPCWSTR String2;

    for (String2 = String; *String2; ++String2);

    return (String2 - String);
}