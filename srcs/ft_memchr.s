section .text
global _ft_memchr

; void * (void * s, int c, size_t len)
;                |      |          |
;                v      v          v
;               rdi    rsi        rdx

_ft_memchr:
search:
    cmp     rdx,    0
    je      ret_null
    cmp     [rdi],  sil
    je      end
    inc     rdi
    dec     rdx
    jmp     search

ret_null:
    mov     rax,    0
    ret

end:
    mov     rax,    rdi
    ret
