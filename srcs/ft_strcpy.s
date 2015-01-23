section .text
global _ft_strcpy

extern _ft_strlen

_ft_strcpy:
    push    rdi
    push    rsi
    push    r12
    mov     r12,    rdi
    mov     rdi,    rsi
    call    _ft_strlen
    cmp     rax,    0
    je      return
    add     rax,    1
    mov     rcx,    rax
    mov     rdi,    r12
    mov     rax,    rdi
    rep     movsb
    pop     r12
    pop     rsi
    pop     rdi

return:
    ret
