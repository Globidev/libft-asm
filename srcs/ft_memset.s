section .text
global _ft_memset

_ft_memset:
    mov     rax,            rdi
    test    rdx,            rdx
    je      ret1
    mov     rcx,            rdx

l1:
    mov     byte [rdi],     sil
    inc     rdi
    loop    l1

ret1:
    ret
