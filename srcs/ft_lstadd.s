section .text
global _ft_lstadd

extern _ft_lstnew

; void ft_lstadd(t_list **alst, t_list *new)
;                          |             |
;                          v             v
;                         rdi           rsi

_ft_lstadd:
    cmp     rdi,                0       ; return if alst is null
    je      return

lstadd:
    mov     r8,                 [rdi]
    mov     qword [rsi + 16],   r8      ; new->next = alst
    mov     [rdi],              rsi     ; alst = new

return:
    ret
