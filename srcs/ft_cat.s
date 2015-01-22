section .data

buff_size   equ     1024

section .text
global _ft_cat

_ft_cat:
    sub     rsp,    buff_size       ; add buffer size to stack top
    mov     rsi,    rsp             ; buffer zone in rsi
    add     rsp,    buff_size       ; restore stack pointer
    mov     r15,    rdi

read:
    mov     rdi,    r15
    mov     rdx,    buff_size       ; size to read in rdx
    mov     rax,    0x2000003       ; read in rax
    syscall                         ; call read
    cmp     rax,    0               ; if read failed / eof ->
    jle     return                  ; abort

write:
    mov     rdi,    1               ; fd in rdi
    mov     rdx,    rax             ; size to write in rdx
    mov     rax,    0x2000004       ; write in rax
    syscall                         ; rsi is fine, call write
    cmp     rax,    -1              ; if write failed
    je      return                  ; abort
    jmp     read                    ; read again

return:
    ret
