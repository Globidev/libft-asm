section .text
global _ft_isalpha

_ft_isalpha:
    cmp     rdi, 'a'
    jge     check_last_min
    cmp     rdi, 'A'
    jge     check_last_maj
    jmp     set_false

check_last_min:
    cmp     rdi, 'z'
    jle     set_true
    jmp     set_false

check_last_maj:
    cmp     rdi, 'Z'
    jle     set_true
    jmp     set_false

set_true:
    mov     rax, 1
    jmp     return

set_false:
    mov     rax, 0

return:
    ret
