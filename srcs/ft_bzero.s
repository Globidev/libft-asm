section .text
global _ft_bzero

_ft_bzero:
    push    rdi
    test    rsi, rsi
    je      return
    mov     rcx, rsi

l1:
    mov     byte [rdi], 0
    inc     rdi
    loop    l1

return:
    pop     rdi
    ret
