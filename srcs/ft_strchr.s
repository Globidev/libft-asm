section .text
global _ft_strchr

; char * (const char * s, int c)
;                      |      |
;                      v      v
;                     rdi    rsi

_ft_strchr:

search:
    cmp     byte [rdi],    sil  ; if *s == c
    je      found
    cmp     byte [rdi],    0    ; end of string
    je      not_found
    inc     rdi                 ; ++s
    jmp     search

found:
    mov     rax,    rdi
    ret

not_found:
    mov     rax,    0
    ret
