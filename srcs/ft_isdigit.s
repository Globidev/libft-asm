section .text
global _ft_isdigit

; int (int c)
;         |
;         v
;        rdi

_ft_isdigit:
    cmp     rdi, '0'
    jge     check_last
    jmp     ret_false

check_last:
    cmp     rdi, '9'
    jle     ret_true
    jmp     ret_false

ret_true:
    mov     rax,    1
    ret

ret_false:
    mov     rax,    0
    ret
