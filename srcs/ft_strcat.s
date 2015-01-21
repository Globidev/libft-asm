section .text
global _ft_strcat

; rdi -> char * dest
; rsi -> char * src

_ft_strcat:
    mov     rax, rdi
    cmp     rdi, 0
    je      ret1
    cmp     rsi, 0
    je      ret1

l1:
    cmp     byte [rdi],  0
    je      cat
    inc     rdi
    jmp     l1

cat:
    cmp     byte [rsi], 0
    je      ret1
    mov     byte [rdi], sil
    inc     rdi
    inc     rsi
    jmp     cat

ret1:
    ret
