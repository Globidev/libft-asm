section .text
global _ft_bzero

; void (void * mem, size_t len)
;              |            |
;              v            v
;             rdi          rsi

_ft_bzero:

l1:
    cmp     rsi,        0   ; while (len != 0)
    je      end
    mov     byte [rdi], 0   ; *mem = 0
    inc     rdi             ; ++mem
    dec     rsi             ; --len
    jmp     l1

end:
    ret
