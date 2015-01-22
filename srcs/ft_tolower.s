section .text
global _ft_tolower

_ft_tolower:
    cmp     rdi, 65
    jge     step1
    jmp     ret1

step1:
    cmp     rdi, 90
    ja      ret1
    add     rdi, 32
    jmp     ret1

ret1:
    mov     rax, rdi
    ret
