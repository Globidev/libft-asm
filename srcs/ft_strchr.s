section .text
global _ft_strchr

; rdi -> char *s
; rsi -> int c

_ft_strchr:
    mov     rax,           0                ;move NULL in rax for return
    cmp     rdi,           0                ;check if rdi is NULL
    je      return                          ;if rdi is NULL return

l1:
    cmp     byte [rdi],    sil              ;cmp current byte
    je      c_found                         ;if current byte == rsi return
    cmp     byte [rdi],    0                ;cmp current byte to NULL
    je      c_not_found                     ;if current byte is NULL return
    inc     rdi                             ;increment rdi
    jmp     l1                              ;loop on every byte of string

c_not_found:
    mov     rax,          0                 ;if c not found return 0
    jmp     return

c_found:
    mov     rax,          rdi               ;move current byte of rdi in rax

return:
    ret
