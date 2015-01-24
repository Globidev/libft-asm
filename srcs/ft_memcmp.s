section .text
global _ft_memcmp

_ft_memcmp:
    mov     rcx,    rdx
    cld
    repe    cmpsb
    ja      greater
    jb      lower
    je      equal

equal:
    mov     rax,    0
    jmp     return

greater:
    mov     rax,    -1
    jmp     return

lower:
    mov     rax,    1
    jmp     return

return:
    ret
