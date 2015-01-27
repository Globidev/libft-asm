section .text
global _ft_toupper

; int (int c)
;         |
;         v
;        rdi

_ft_toupper:
    cmp     rdi,     'a'
    jge     step1
    jmp     return

step1:
    cmp     rdi,     'z'
    ja      return
    sub     rdi,     32
    jmp     return

return:
    mov     rax,    rdi
    ret
