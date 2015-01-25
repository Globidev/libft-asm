section .text
global _ft_strstr

extern _ft_puts

; rdi -> char *s1
; rsi -> char *s2

_ft_strstr:
    mov     rax,           0                ;move NULL in rax for return
    cmp     rdi,           0                ;check if rdi is NULL
    je      s1_empty                        ;if rdi is NULL check rsi
    cmp     byte [rsi],    0                ;check if rsi is NULL
    je      s2_empty                        ;if rsi is null return s1
    push    rdi                             ;save rdi on stack
    push    rsi                             ;save rsi on stack

l1:
    ; mov     r12,    rdi
    ; mov     r11,    rsi
    ; call    _ft_puts
    ; mov     rdi,    r12
    ; mov     rsi,    r11
    cmp     byte [rdi],    "W"              ;cmp current char of s1
    je      c_found                         ;if current char == rsi 1st char
    cmp     byte [rdi],    0                ;cmp current byte to NULL
    je      c_not_found                     ;if current byte is NULL return
    inc     rdi                             ;increment rdi
    jmp     l1                              ;loop on every byte of string

c_not_found:
    mov     rax,           0                ;if s2 not found return 0
    pop     rdi
    pop     rsi
    jmp     return


find_s2:
    inc     r11
    inc     r12
    cmp     r12b,   0
    je      s2_found
    cmp     r11b,   r12b
    jne     l1

c_found:
    mov     r11,    rdi                     ;create tmp of rdi
    mov     r12,    rsi                     ;create tmp of rsi
    inc     rdi                             ;inc rdi
    jmp     find_s2                         ;try remaining of s2

s2_found:
    mov     rax,           rdi
    pop     rdi
    pop     rsi
    jmp     return

s1_empty:
    cmp     rsi,           0                ;if s2 empty to, return s1
    jne     return

s2_empty:
    mov     rax,          rdi

return:
    ret
