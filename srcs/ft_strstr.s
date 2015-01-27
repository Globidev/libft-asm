section .text
global _ft_strstr

; char * (const char *s1, const char *s2)
;                     |               |
;                     v               v
;                    rdi             rsi

_ft_strstr:
    cmp     byte [rsi], 0               ;if *s2 == 0, return s1
    je      found
    cmp     byte [rdi], 0               ;if *s1 == 0, return 0
    je      not_found

search_s1:
    mov     r8,         [rdi]
    mov     r9,         [rsi]
    cmp     byte [rdi], r9b             ;if *s1 == *s2, search for s2
    je      init_search_s2
    cmp     byte [rdi], 0               ;if *s1 == 0, s2 not found
    je      not_found
    inc     rdi
    jmp     search_s1

init_search_s2:
    mov     rdx,        rdi
    mov     rcx,        rsi
    jmp     search_s2

ret_search_s1:
    inc     rdi
    jmp     search_s1

search_s2:
    inc     rdx                         ;inc *s1
    inc     rcx                         ;inc *s2
    mov     r11,        [rcx]
    cmp     r11b,       0               ;if *s2 == 0, s2 found
    je      found
    cmp     byte [rdx], r11b            ;if *s1 != *s2, return to search_s1
    jne     ret_search_s1
    cmp     byte [rdx], 0               ;if *s1 == 0, s2 not found
    je      not_found
    jmp     search_s2

found:
    mov     rax,        rdi
    ret

not_found:
    mov     rax,        0
    ret
