section .text
global _ft_strclr

extern _ft_bzero, _ft_strlen

;void ft_strclr(char *s)
;                     |
;                     v
;                    rdi

_ft_strclr:
    push    rdi
    call    _ft_strlen
    pop     rdi
    mov     rsi,    rax
    call    _ft_bzero
    ret