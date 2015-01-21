section .text
global _ft_strlen

_ft_strlen:
    mov     rax,    0

get_len:
    cmp     byte [rdi],     0
    je      ret
    inc     rdi
    inc     rax
    jmp     get_len

ret:
    ret
