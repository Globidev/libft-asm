section .text
global _ft_tolower

; int (int c)
;         |
;         v
;        rdi

_ft_tolower:
    cmp     rdi,     'A'
    jge     step1
    jmp     return

step1:
    cmp     rdi,     'Z'
    ja      return
    add     rdi,     32
    jmp     return

return:
    mov     rax,    rdi
    ret
