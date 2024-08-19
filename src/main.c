
#include "../include/Native.h"
#include "../include/Common.h"
#include "../include/Utils.h"

VOID Main() {
    PVOID kernel32 = {0};
    CHAR  String[] = { 'c', 'a', 'l', 'c', '.', 'e', 'x', 'e', 0 }; // "calc.exe" string
    PWINEXEC pWinExec = NULL;

    if ((kernel32 = GetModuleHandleH(kernel32dll_CRC32))) {
        if ((pWinExec = (PWINEXEC)GetProcAddressH(kernel32, WinExec_CRC32))) {
            pWinExec(String, TRUE);
        }
    }
}