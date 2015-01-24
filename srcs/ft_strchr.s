section .text
global _ft_strchr

; rdi -> char *s
; rsi -> int c

_ft_strchr:
    mov     rax,           0                ;move NULL in rax for return
    cmp     rdi,           0                ;check if rdi is NULL
    je      return                          ;if rdi is NULL return
    push    rdi                             ;save rdi on stack 

l1:
    cmp     byte [rdi],    0                ;cmp current byte to NULL
    je      return2                         ;if current byte is NULL return
    cmp     byte [rdi],    sil              ;cmp current byte
    je      return1                         ;if current byte == rsi return
    inc     rdi                             ;increment rdi
    jmp     l1                              ;loop on every byte of string

return2:
    mov     rax,          0
    pop     rdi
    jmp     return

return1:
    mov     rax,          rdi               ;move current byte of rdi in rax
    pop     rdi                             ;restore rdi

return:
    ret
