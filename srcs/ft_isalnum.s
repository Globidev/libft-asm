section .text
global _ft_isalnum

extern _ft_isalpha
extern _ft_isdigit

; int (int c)
;         |
;         v
;        rdi

_ft_isalnum:
    push    rbx
    mov     rbx,    rdi ; save rdi across calls
    call    _ft_isalpha
    cmp     rax,    1
    je      end         ; return if alpha
    mov     rdi,    rbx ; restore rdi before call
    call    _ft_isdigit

end:
    pop rbx
    ret
