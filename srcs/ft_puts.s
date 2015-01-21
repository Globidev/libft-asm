section .text
global _ft_puts

_ft_puts:
    cmp     rdi,        0
    je      ret_fail
    mov     rsi,        rdi
    mov     r8,         rdi
    mov     rdi,        1
    mov     rdx,        0

get_len:
    cmp     byte [r8],  0
    je      display
    inc     r8
    inc     rdx
    jmp     get_len

display:
    mov     rax,    0x2000004
    syscall
    push    10
    mov     rsi,    rsp
    mov     rdx,    1
    mov     rax,    0x2000004
    syscall
    pop     rsi
    jmp     ret_success

ret_success:
    mov     rax,    10
    ret

ret_fail:
    mov     rax,    -1
    ret

