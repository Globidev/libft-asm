section .text
global _ft_memalloc

extern  _ft_bzero
extern  _malloc

; void * (size_t size)
;                 |
;                 v
;                rdi

_ft_memalloc:
    push    rbx         ; using rbx as a non volatile to store the size
    mov     rbx,    rdi
    call    _malloc
    cmp     rax,    0   ; malloc failed
    je      end
    mov     rsi,    rbx ; size as the second argument of bzero
    mov     rbx,    rax ; saving malloc return address
    mov     rdi,    rax ; malloc return address as the first argument of bzero
    call    _ft_bzero
    mov     rax,    rbx ; restoring the return address to be returned here

end:
    pop rbx
    ret

