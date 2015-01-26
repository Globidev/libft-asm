section .text
global _ft_memdel

extern _free

; void (void ** mem_ptr)
;                  |
;                  v
;                 rdi

_ft_memdel:
    cmp     rdi,    0           ; if (mem_ptr)
    je      end
    push    rbx                 ; using rbx to save mem_ptr (non volatile)
    mov     rbx,    rdi
    mov     rdi,    [rbx]       ; passing *mem_ptr to _free
    call    _free
    mov     qword [rbx],    0   ; *mem_ptr = 0
    pop     rbx

end:
    ret
