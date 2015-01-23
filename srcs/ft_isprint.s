section .text
global _ft_isprint

; int (int c)
;         |
;         v
;        rdi

_ft_isprint:
    cmp     rdi, 32
    jge     check_last
    jmp     ret_false

check_last:
    cmp     rdi, 126
    jle     ret_true
    jmp     ret_false

ret_true:
    mov     rax, 1
    ret

ret_false:
    mov     rax, 0
    ret
