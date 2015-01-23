section .text
global _ft_isalnum

extern _ft_isalpha
extern _ft_isdigit

_ft_isalnum:
    push    r12
    call    _ft_isalpha
    mov     r12, rax
    cmp     r12, 0
    je      isdigit
    pop     r12
    ret

isdigit:
    call    _ft_isdigit
    pop     r12
    ret
