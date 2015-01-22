section .text
global _ft_memcpy

; rcx -> nbr de rep
; rsi -> src
; rdi -> dest
; rep movsb
; rdx -> size_t n

_ft_memcpy:
    mov     rax,    rdi
    cmp     rcx,    0
    je     ret1
    mov     rcx,    rdx

copy:
    cld
    rep     movsb

ret1:
    ret
