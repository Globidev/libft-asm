section .text
global _ft_strncmp

; int (const char * s1, const char * s2, size_t len)
;                    |                |          |
;                    v                v          v
;                   rdi              rsi        rdx

_ft_strncmp:
    mov     r8,     rdi
    or      r8,     rsi ; if (!s1 && !s2)
    cmp     r8,     0   ; return 0
    je      equal

cmp_loop:
    cmp     rdx,    0
    je      equal
    mov     r8,     [rdi]
    cmp     r8,     0
    je      bcmp
    cmp     byte [rsi],  0
    je      bcmp
    cmp     r8b,    byte [rsi]
    ja      greater
    jb      lower
    inc     rdi
    inc     rsi
    dec     rdx
    jmp     cmp_loop

bcmp:
    cmp     r8b,    byte [rsi]
    ja      greater
    jb      lower
    je      equal

equal:
    mov     rax,    0
    ret

greater:
    mov     rax,    1
    ret

lower:
    mov     rax,    -1
    ret
