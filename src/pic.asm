;; Assembly code

;; Call C function
EXTERN Main

GLOBAL Start
segment .text
;; Shellcode entrypoint
    Start:
        push rsi
        mov rsi, rsp
        and rsp, byte - 0x10 ; align stack with 16 bytes
        sub rsp, 0x20 ; allocate space for our C function
        call Main
        mov rsp, rsi
        pop rsi
        ret