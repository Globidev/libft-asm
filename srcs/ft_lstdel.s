section .text
global _ft_lstdel

extern _free

_ft_lstdel:
    push    rbx                                 ;save rbx on the stack
    push    rbp                                 ;save rbp on the stack
    cmp     rdi,            0                   ;return if alst is null
    je      return
    mov     rbx,            [rdi]               ;put dereferenced alst in rbx
    mov     rbp,            rbx                 ;put dereferenced alst in rbp
    mov     rdi,            [rbx]

lstdel:

    free_content:
        mov     rbx,        qword [rdi + 16]    ;rbx = current->next
        call    _free                           ;free current->content element

    free_element:
        mov     rdi,        rbp                 ;put dereferenced alst in rdi
        call    _free                           ;free current element

    cmp     rbx,            0                   ;check current->next
    je      return

    mov     rdi,            [rbx]               ;put next in current
    jmp     lstdel

return:
    pop     rbp
    pop     rbx
    ret
