section .text
global _ft_memcmp

; int (const void * s1, const void * s2, size_t len)
;                    |                |          |
;                    v                v          v
;                   rdi              rsi        rdx

_ft_memcmp:
    mov     rcx,    rdx
    cld
    repe    cmpsb
    ja      greater
    jb      lower
    je      equal

equal:
    mov     rax,    0
    ret

greater:
    mov     rax,    -1
    ret

lower:
    mov     rax,    1
    ret
