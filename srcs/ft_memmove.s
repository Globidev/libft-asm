section .text
global _ft_memmove

_ft_memmove:
    mov     r8,     rdi
    or      r8,     rsi
    cmp     r8,     0
    je      ret_null
    mov     rax,    rdi
    mov     rcx,    rdx
    cld
    rep     movsb

end:
    ret

ret_null:
    mov     rax,    0
    ret
