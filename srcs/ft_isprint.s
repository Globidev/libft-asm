section .text
global _ft_isprint

_ft_isprint:
    push    rdi
    cmp     rdi, 32
    jge     check_last
    jmp     set_false

check_last:
    cmp     rdi, 126
    jle     set_true
    jmp     set_false

set_true:
    mov     rax, 1
    jmp     return

set_false:
    mov     rax, 0

return:
    pop     rdi
    ret
