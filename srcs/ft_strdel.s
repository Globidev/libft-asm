section .text
global _ft_strdel

extern _ft_memdel

_ft_strdel:
    call    _ft_memdel