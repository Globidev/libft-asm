section .text
global _ft_toupper

_ft_toupper:
    mov     r8,     rdi
    cmp     r8,     97
    jge     step1
    jmp     return

step1:
    cmp     r8,     122
    ja      return
    sub     r8,     32
    jmp     return

return:
    mov     rax,    r8
    ret
