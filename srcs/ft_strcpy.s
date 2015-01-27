section .text
global _ft_strcpy

; char * (char * dst, const char * src)
;                 |                 |
;                 v                 v
;                rdi               rsi

_ft_strcpy:
    mov     r8,     rdi
    or      r8,     rsi ; if (!s1 && !s2)
    cmp     r8,     0   ; return 0
    je      ret_null
    mov     rax,    rdi

cpy:
    cmp     byte [rsi],  0
    je      end
    mov     r8,     [rsi]
    mov     [rdi],  r8b
    inc     rdi
    inc     rsi
    jmp     cpy

end:
    mov     byte [rdi],  0
    ret

ret_null:
    mov     rax,    0
    ret
