section .text
global _ft_strcmp

extern _ft_strlen

_ft_strcmp:
    mov     rax,    0
    cmp     rdi,    0
    je      return
    cmp     rsi,    0
    je      return

cmp_loop:
    cmp     dil,    0
    je      bcmp
    cmp     sil,    0
    je      bcmp
    cmp     dil,    sil
    ja      greater
    jb      lower
    inc     rdi
    inc     rsi
    jmp     cmp_loop

equal:
    mov     rax,    0
    jmp     return

greater:
    mov     rax,    1
    jmp     return

lower:
    mov     rax,    -1
    jmp     return

bcmp:
    cmp     dil,    sil
    ja      greater
    jb      lower
    je      equal

return:
    ret
