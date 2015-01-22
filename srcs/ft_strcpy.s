section .text
global _ft_strcpy

extern _ft_strlen

_ft_strcpy:
    mov     r15,    rdi
    mov     rdi,    rsi
    call    _ft_strlen
    mov     rcx,    rax
    mov     rdi,    r15
    cld
    rep     movsb
    mov     rax,    rdi
    ret
