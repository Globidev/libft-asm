section .text
global  _ft_strnew

extern  _ft_memalloc

_ft_strnew:
    add     rdi, 1              ; Add 1 for '\0'
    call    _ft_memalloc        ; Easy Life
    ret                         ; Nothins to do here !
