section .text
global  _ft_strnew

extern  _ft_memalloc

; char * (size_t size)
;                 |
;                 v
;                rdi

_ft_strnew:
    add     rdi, 1          ; Add 1 for the additional '\0'
    jc      fail            ; unsigned overflow test
    call    _ft_memalloc    ; Easy Life
    ret                     ; Nothing to do here !

fail:
    mov     rax,    0
    ret
