section .text
global _ft_atoi

_ft_atoi:
    mov     rax,    0
    cmp     rdi,    0
    je      return
    mov     r9,     10
    mov     r8,     [rdi]
    mov     r10,    1
    cmp     r8b,    '-'
    je      negative

get_number:
    mov     r11,    [rdi]
    cmp     r11b,   '0'
    jl      get_sign
    cmp     r11b,   '9'
    jg      get_sign
    mul     r9
    sub     r11,    48
    add     al,     r11b
    inc     rdi
    cmp     rax,    214748364
    je      limit
    jmp     get_number

get_sign:
    mul     r10

return:
    ret

negative:
    mov     r10,    -1
    inc     rdi
    jmp     get_number

limit:
    cmp     r10,    1
    je      get_number
    mov     r11,    [rdi]
    cmp     r11b,   '8'
    jne     get_number
    mul     r9
    mul     r10
    sub     rax,    8
    jmp     return
