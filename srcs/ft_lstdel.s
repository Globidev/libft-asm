section .text
global _ft_lstdel

extern _free

; void ft_lstdel((t_list **alst, t_deleter del)
;                           |               |
;                           v               v
;                          rdi             rsi

_ft_lstdel:
    cmp     rdi,    0           ; if (alst)
    je      end
    push    rbx
    mov     rbx,    rdi         ; rbx -> alst
    push    rbp
    mov     rbp,    [rdi]       ; it = *alst
    push    r12
    mov     r12,    rsi         ; r12 -> del

lstdel:
    cmp     rbp,    0           ; while (it)
    je      nullify
    mov     rdi,    [rbp]       ; del(
    mov     rsi,    [rbp + 8]   ;   it->content,
    call    r12                 ;   it->content_size)
    mov     rdi,    rbp         ; temp = it
    mov     rbp,    [rbp + 16]  ; it = it->next
    call    _free               ; free(temp)
    jmp     lstdel

nullify:
    mov     qword [rbx],    0   ; *alst = 0
    pop     r12
    pop     rbp
    pop     rbx

end:
    ret
