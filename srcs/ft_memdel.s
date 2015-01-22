section .text
global _ft_memdel

extern _free

_ft_memdel:
    cmp     rdi,    0       ;check if rdi is null
    je      ret_null
    push    rdi             ;save base pointer
    mov     rdi,    [rdi]   ;dereference pointer for _free

dealloc:
    call    _free
    pop     rdi
    xor     r8,       r8
    mov     [rdi],    r8


ret_null:
    mov     rax,    0

return:
    ret
