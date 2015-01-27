section .text
global _ft_memccpy

; void * (void * dst, const void * src, int c, size_t len)
;                 |                 |       |          |
;                 v                 v       v          v
;                rdi               rsi     rdx        rcx

_ft_memccpy:

copy:
    cmp     rcx,    0           ; len char copied
    je      ret_null            ; -> return 0
    mov     r8,     [rsi]
    mov     byte [rdi], r8b     ; *dst = *src
    cmp     [rsi],  dl          ; search c
    je      ret_sucess
    inc     rdi                 ; ++dst
    inc     rsi                 ; ++src
    dec     rcx                 ; --len
    jmp     copy

ret_null:
    mov     rax,    0
    ret

ret_sucess:
    inc     rdi
    mov     rax,    rdi
    ret
