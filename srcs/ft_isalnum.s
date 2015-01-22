section .text
global _ft_isalnum

extern _ft_isalpha
extern _ft_isdigit

_ft_isalnum:
    call    _ft_isalpha
    mov     r8, rax
    cmp     r8, 0
    je      isdigit
    ret

isdigit:
    call    _ft_isdigit
    ret
