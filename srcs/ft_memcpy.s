section .text
global _ft_memcpy

_ft_memcpy:
    mov     rax,            rdi
    test    rdx,            rdx
    je      ret1
    mov     rcx,            rdx

l1:
    mov     byte [rdi],     sil
    inc     rdi
    inc     rsi
    jmp     ret1
    loop    l1

ret1:
    ret
