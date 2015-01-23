section .text
global _ft_puts

_ft_puts:
    cmp     rdi,    0
    je      return
    push    rdi
    push    rsi
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
    je      return
    push    10
    mov     rsi,    rsp
    mov     rdi,    1
    mov     rdx,    1
    mov     rax,    0x2000004
    syscall
    pop     r8
    cmp     rax,    -1
    je      return
    mov     rax,    10

return:
    pop     rsi
    pop     rdi
    ret

