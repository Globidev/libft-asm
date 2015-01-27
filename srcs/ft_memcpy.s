section .text
global _ft_memcpy

; void * (void * dest, const void * src, size_t len)
;                 |                  |           |
;                 v                  v           v
;                rdi                rsi         rdx

_ft_memcpy:
    mov     rax,    rdi ; set return value
    mov     rcx,    rdx ; setting len iterations
    cld                 ; ++rdi and ++rsi at each iteration
    rep     movsb       ; *rdi = *rsi

end:
    ret
