section .text
global _ft_memalloc

extern  _ft_bzero
extern  _malloc

; rdi -> size_t size

_ft_memalloc:
    push    rdi                ; Push rdi for save him before _malloc
    call    _malloc
    cmp     rax, 0             ; Check if _malloc works
    je      ret_fail
    pop     rsi                ; Recup rdi in rsi
    mov     rdi, rax           ; Put rax in rdi for _ft_bzero
    push    rax                ; Push rax for save him before _ft_bzero
    call    _ft_bzero
    pop     rax                ; Recup rax

ret1:
    ret

ret_fail:
    pop     r8                 ; Recup rdi if malloc fail
    ret


