section .text
global _ft_strstr

extern  _ft_puts

; rdi -> char *s1
; rsi -> char *s2

_ft_strstr:
    mov     rax,           0                ;move NULL in rax for return
    cmp     rdi,           0                ;check if rdi is NULL
    je      s1_empty                        ;if rdi is NULL check rsi
    cmp     byte [rsi],    0                ;check if rsi is NULL
    je      s2_empty                        ;if rsi is null return s1
    mov     r11,           [rsi]

l1:
    mov     r10,        [rdi]
    cmp     r10b,       r11b                ;cmp s1 8bits & s2 8bits
    je      c_found                         ;if s1 == s2
    cmp     r10b,       0                   ;cmp s2 8bits to NULL
    je      return                          ;if s1 is NULL return
    inc     rdi                             ;increment s1
    jmp     l1                              ;loop on every byte of string

find_s2:
    inc     r8                             ;inc r8 (s1)
    inc     r9                             ;inc r9 (s2)
    mov     rdx,        [r8]               ;s1 current char in rdx
    mov     rcx,        [r9]               ;s2 current char in rcx
    cmp     ch,         '\0'               ;if end of s2 return s2 found
    je      s2_found
    cmp     dh,         '\0'               ;if end of s1 return (s2 not found)
    je      return
    cmp     dh,         ch                 ;compare s1 & s2
    jne     l1                             ;if not equal return in l1
    ; dislay
    push    r12
    mov     r12,    rdi
    mov     rdi,    r9
    call    _ft_puts
    mov     rdi,    r12
    pop     r12
    ; display end
    jmp     find_s2                        ;if not, continue cmp

c_found:
    mov     r8,         rdi                ;create tmp of s1
    mov     r9,         rsi                ;create tmp of s2
    inc     rdi                            ;inc s1
    jmp     find_s2                        ;try remaining of s2

s2_found:
    mov     rax,          rdi
    jmp     return

s1_empty:
    cmp     rsi,          0                ;if s2 empty to, return s1
    jne     return

s2_empty:
    mov     rax,          rdi               ;return ptr of s1

return:
    ret
