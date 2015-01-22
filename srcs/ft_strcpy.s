section .text
global _ft_strcpy

extern _ft_strlen

_ft_strcpy:
    mov     r10,    rdi
    mov     rdi,    rsi
    call    _ft_strlen
    cmp     rax,    0
    je      ret_test
    mov     rcx,    rax
    mov     rdi,    r10
    mov     rax,    rdi
    rep     movsb
    ret

ret_test:
    ret
