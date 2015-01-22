section .text
global _ft_puts

_ft_puts:
    cmp     rdi,    0
    je      ret_fail
    mov     rsi,    rdi
    mov     rdi,    1
    mov     rdx,    0
    mov     rax,    0x2000004

get_len:
    cmp     byte [rsi + rdx], 0
    je      display
    inc     rdx
    jmp     get_len

display:
    syscall
    cmp     rax,    -1
    je      ret_fail
    push    10
    mov     rsi,    rsp
    mov     rdx,    1
    mov     rax,    0x2000004
    syscall
    pop     rsi
    cmp     rax,    -1
    je      ret_fail

ret_success:
    mov     rax,    10
    ret

ret_fail:
    ret

