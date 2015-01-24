section .text
global _ft_strncmp

_ft_strncmp:
    mov     rax,    0
    cmp     rdi,    0
    je      return
    cmp     rsi,    0
    je      return
    cmp     rdx,    0
    je      return

cmp_loop:
    mov     r8,     [rdi]
    mov     r9,     [rsi]
    cmp     r8,     0
    je      bcmp
    cmp     r9,     0
    je      bcmp
    cmp     r8b,    r9b
    ja      greater
    jb      lower
    dec     rdx
    cmp     rdx,    0
    je      bcmp
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
    cmp     r8b,    r9b
    ja      greater
    jb      lower
    je      equal

return:
    ret
