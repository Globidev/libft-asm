section .text
global _ft_strncpy

; char * (char * dst, const char * src, size_t len)
;                 |                 |           |
;                 v                 v           v
;                rdi               rsi         rdx

_ft_strncpy:
    mov     r8,     rdi
    or      r8,     rsi ; if (!dst && !src)
    cmp     r8,     0   ; return 0
    je      ret_null
    mov     rax,    rdi

cpy:
    cmp     byte [rsi], 0
    je      zero_fill
    cmp     rdx,    0
    je      end
    mov     r8,     [rsi]
    mov     [rdi],  r8b
    inc     rdi
    inc     rsi
    dec     rdx
    jmp     cpy

zero_fill:
    cmp     rdx,    0
    je      end
    mov     byte [rdi], 0
    dec     rdx
    jmp     zero_fill

end:
    ret

ret_null:
    mov     rax,    0
    ret
