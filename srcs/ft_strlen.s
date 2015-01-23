section .text
global _ft_strlen

_ft_strlen:
    mov     rax,    0

get_len:
    cmp     byte [rdi], 0
    je      return
    mov     al, 0           ;Byte to search in rdi
    mov     rcx,    -1      ;Start count at -1
    push    rdi
    cld                     ;Increment rdi at each turn of repne
    repne   scasb           ;Scan string for al (NULL), decrementing rcx at each turn
    pop     rdi
    mov     rax,    -2      ;rcx will be -2 for length 0, -3 for length 1, ...
    sub     rax,    rcx     ;Length in rax

return:
    ret
