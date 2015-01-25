section .text
global _ft_strlen

; size_t (const char * str)
;                       |
;                       v
;                      rdi

_ft_strlen:
    mov     al,     0       ; set end condition to null termination
    mov     rcx,    -1      ; we don't want any counter to prevent looping
    cld                     ; ++rdi at each iteration
    repne   scasb           ; scan rdi for al (--rcx after each iteration)
    mov     rax,    -2      ; rcx = -rax -2 => rax = -2 - rcx
    sub     rax,    rcx

return:
    ret
