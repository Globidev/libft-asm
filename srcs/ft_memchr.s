section .text
global _ft_memchr

_ft_memchr:
    push    rdi
    cmp     rdi,    0
    je      ret_null
    cmp     rdx,    0
    je      ret_null
    mov     r10,    0

search:
    cmp     r10,    rdx
    jg      ret_null
    cmp     byte [rdi],  0
    je      ret_null
    mov     rax,    rdi
    cmp     [rdi],  sil
    je      return
    inc     rdi
    inc     r10
    jmp     search

ret_null:
    mov     rax,    0

return:
    pop     rdi
    ret
