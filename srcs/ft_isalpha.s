section .text
global _ft_isalpha

; int (int c)
;         |
;         v
;        rdi

_ft_isalpha:
    cmp     rdi,    'a'
    jge     check_last_low
    cmp     rdi,    'A'
    jge     check_last_up
    jmp     ret_false

check_last_low:
    cmp     rdi,    'z'
    jle     ret_true
    jmp     ret_false

check_last_up:
    cmp     rdi,    'Z'
    jle     ret_true
    jmp     ret_false

ret_true:
    mov     rax,    1
    ret

ret_false:
    mov     rax,    0
    ret
