section .text
global _ft_strncpy

extern _ft_strlen

; rdi -> char *dest
; rsi -> char *src
; rdx -> size_t

_ft_strncpy:
    push    rdi                     ;save rdi on stack
    push    rsi                     ;save rsi on stack
    push    r12                     ;save r12 on stack
    mov     r12,    rdi             ;move first arg in r12
    mov     rdi,    rsi             ;move second arg in rdi
    call    _ft_strlen              ;call strlen with rdi (second arg)
    cmp     rax,    0               ;cmp rax to 0
    je      return                  ;if rax at 0, return
    add     rax,    1               ;increment rax for '\0'
    mov     rdi,    r12             ;move r12 (first arg) in rdi
    mov     rax,    rdi             ;move rdi (first arg) in rax
    mov     rcx,    rdx             ;move rdx in rcx for count
    cld
    rep     movsb                   ;copy rcx char
    pop     r12                     ;restore r12
    pop     rsi                     ;restore rsi
    pop     rdi                     ;restore rdi

return:
    ret
