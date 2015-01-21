section .text
global _ft_isascii

_ft_isascii: 
    cmp     rdi, 0
    jge     check_last
    jmp     set_false

check_last:
    cmp     rdi, 127
    jle     set_true
    jmp     set_false

set_true:
    mov     rax, 1
    jmp     return

set_false:
    mov     rax, 0

return:
    ret
