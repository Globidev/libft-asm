section .text
global _ft_bzero

_ft_bzero:
    test    rsi, rsi
    je      ret1
    mov     rcx, rsi

l1:
    mov     byte [rdi], 0
    inc     rdi
    loop    l1

ret1:
    ret