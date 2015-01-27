section .text
global _ft_strdel

extern _ft_memdel

;void ft_strdel(char **as)
;                       |
;                       v
;                      rdi

_ft_strdel:
    call    _ft_memdel
    ret