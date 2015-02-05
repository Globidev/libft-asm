section .text
global _ft_lstnew

extern _malloc, _ft_memcpy

_ft_lstnew:

    save_content:
        push    rbx
        mov     rbx,    rdi     ;rbx->content

    save_content_size:
        push    rbp
        mov     rbp,    rsi     ;rbp->content_size

    mov     rdi,        24      ;initialize malloc size
    call    _malloc             ;allocate enough space for list struct
    test    rax,        rax     ;test if malloc succeeded
    je      return
    push    rax

get_args:
    cmp     rbp,        0       ;check if content_size is not null
    jne     create_elem
    mov     qword [rax],    0
    jmp     bzero_next

create_elem:
    mov     rdi,        rbp     ;initialize malloc size
    call    _malloc             ;malloc of content_size
    test    rax,        rax     ;test if malloc succeeded
    je      bzero_next
    pop     r8                  ;get struct return address
    mov     [r8],       rax
    push    r8
    mov     rdi,        rax     ;initialize dest for memcpy
    mov     rsi,        rbx     ;initialize src for memcpy
    mov     rdx,        rbp     ;initialize size for memcpy
    call    _ft_memcpy

bzero_next:
    pop     rax
    mov     [rax + 8],  rbp
    mov     qword [rax + 16], 0 ;set next to 0

return:
    pop     rbp
    pop     rbx
    ret
