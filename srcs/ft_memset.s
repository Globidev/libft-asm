section .text
global _ft_memset

_ft_memset:
    test    rdx,    rdx
    je      return
    mov     rax,    rsi
    mov     rcx,    rdx
    push    rdi
    cld
    rep     stosb
    pop     rdi

return:
    mov     rax,    rdi
    ret


; stosb ==> put al in rdi, cld to inc rdi, then rep
