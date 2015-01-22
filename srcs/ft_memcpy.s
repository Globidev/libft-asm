section .text
global _ft_memcpy

; rcx -> nbr de rep
; rsi -> src
; rdi -> dest
; rep movsb
; rdx -> size_t n

_ft_memcpy:
    mov     rax,    rdi ;set return value
    cmp     rdx,    0	;check nbr of rep 
    je     ret1
    mov     rcx,    rdx ;set rcx

copy:
    cld
    rep     movsb		;betonic memcpy

ret1:
    ret
