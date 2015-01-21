section .text
global _ft_strdup

align   16
extern  _malloc

_ft_strdup:
    cmp     rdi,            0
    je      ret_success
    mov     r9,             rdi
    mov     r8,             0

get_len:
    cmp     byte [r9],      0
    je      alloc
    inc     r9
    inc     r8
    jmp     get_len

alloc:
    ;mov     rdx,            20
    ;push    rdx
    push    20
    call    _malloc
    add     rsp,            4
    test    rax,            rax
    jz      ret_fail
    mov     rdx,            rax

copy:
    cmp     byte [rdi],     0
    je      ret_success
    mov     byte [rdx],     dil
    inc     rdx
    inc     rdi
    jmp     copy

ret_success:
    ret

ret_fail:
    mov     rax,            0
    ret
