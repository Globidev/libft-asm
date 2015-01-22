section .text
global _ft_strdup

extern  _malloc

; rdi -> str (1st ARG)

_ft_strdup:
    cmp     rdi,    0       ; if str is null
    je      ret_null        ; return null
    mov     r14,    rdi     ; r14 points to str (not altered by malloc)
    mov     r15,    0       ; r15 is a counter for the len

get_len:
    cmp     byte [r14 + r15],   0
    je      alloc
    inc     r15
    jmp     get_len

alloc:
    add     r15,    1       ; For the null termination
    mov     rdi,    r15     ; Passes the len as the first malloc argument
    call    _malloc
    cmp     rax,    0       ; malloc failed
    je      return

copy:
    cmp     r15,    0       ; reusing r15 for reverse looping
    jl      return
    mov     r8, [r14 + r15] ; r8 as a temporary for mem to mem copy
    mov     [rax + r15], r8b
    dec     r15
    jmp     copy

ret_null:
    mov     rax,    0

return:
    ret
