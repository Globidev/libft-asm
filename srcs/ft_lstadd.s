section .text
global _ft_lstadd

extern _ft_lstnew

_ft_lstadd:
    cmp     rdi,                0   ;return if alst is null
    je      return

lstadd:
    mov     qword [rsi + 16],   rdi ;new->next = alst
    mov     [rdi],              rsi ;alst = new

return:
    ret
