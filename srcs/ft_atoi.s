section .text
global _ft_atoi

extern _ft_isdigit

_ft_atoi:
    mov     rax,    0
    cmp     rdi,    0
    je      return
    push    r12
    push    r13
    push    r14
    mov     r12,    10
    mov     r8,     [rdi]
    mov     r13,    1
    cmp     r8b,    '-'
    je      negative

get_number:
    mov     r14,    [rdi]
    cmp     r14b,   '0'
    jl      get_sign
    cmp     r14b,   '9'
    jg      get_sign
    mul     r12
    sub     r14,    48
    add     al,     r14b
    inc     rdi
    jmp     get_number

get_sign:
    mul     r13

restore:
    pop     r14
    pop     r13
    pop     r12

return:
    ret

negative:
    mov     r13,    -1
    inc     rdi
    jmp     get_number

test_return:
    ; mov     r9,     10
    ; mov     rax,    0
    ; add     rax,    r9
    ; mul     r12
    mov     r14,    [rdi]
    mov     al,     r14b

    ; add     rax,    r14
    pop     r14
    pop     r13
    pop     r12
    ret
