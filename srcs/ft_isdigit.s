section .text
global _ft_isdigit

_ft_isdigit:
    push    rdi
    cmp     rdi, '0'
    jge     check_last
    jmp     set_false

check_last:
    cmp     rdi, '9'
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
