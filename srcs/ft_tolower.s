section .text
global _ft_tolower

_ft_tolower:
    mov     r8,     rdi
    cmp     r8,     65
    jge     step1
    jmp     return

step1:
    cmp     r8,     90
    ja      return
    add     r8,     32
    jmp     return

return:
    mov     rax,    r8
    ret
