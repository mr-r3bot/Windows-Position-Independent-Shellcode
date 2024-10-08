## Build
```
cmake --build <output_dir> --target Windows_PIC -j 14
```

## Extract shellcode from PE file

```
python scripts/extract.py -f <Windows_PIC.exe> -o output.bin
```

![image](https://github.com/user-attachments/assets/148aa452-96f2-475c-9434-95db625d7804)

### Validate shellcode

```
LPVOID addressPointer = VirtualAlloc(NULL, sizeof(buf), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
if (addressPointer) {
	RtlMoveMemory(addressPointer, buf, sizeof(buf));
	HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)addressPointer, NULL, 0, 0);
	if (hThread) {
		WaitForSingleObject(hThread, INFINITE);
	}
}
```
