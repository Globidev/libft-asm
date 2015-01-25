section .text
global _ft_memset

; void * (void * dest, int c, size_t len)
;                 |        |          |
;                 v        v          v
;                rdi      rsi        rdx

_ft_memset:
    cmp     rdx,    0
    je      end
    mov     r8,     rdi ; saving dest to be restored later
    mov     rax,    rsi
    mov     rcx,    rdx ; setting len iterations
    cld                 ; ++rdi at each iteration
    rep     stosb       ; *rdi = c

end:
    mov     rax,    r8
    ret
