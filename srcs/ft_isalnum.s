section .text
global _ft_isalnum

extern _ft_isalpha
extern _ft_isdigit

; int (int c)
;         |
;         v
;        rdi

_ft_isalnum:
    push    rdi         ; save rdi across calls
    call    _ft_isalpha
    pop     rdi         ; popping rdi back
    cmp     rax,    0
    je      end         ; if non alpha -> ret 0
    call    _ft_isdigit

end:
    ret
