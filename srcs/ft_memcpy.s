section .text
global _ft_memcpy

_ft_memcpy:
    mov     rax,    rdi
    test    rdx,    rdx
    je      ret1
    mov     rcx,    rdx

copy:
    mov     r15,    [rsi + rcx]
    mov     [rdi + rcx],    r15b
    loop    copy
    mov     r15,    [rsi]
    mov     [rdi],  r15b

ret1:
    ret
