section .text
global _ft_strdup

extern  _malloc
extern  _ft_strlen

; rdi -> str (1st ARG)

_ft_strdup:
    cmp     rdi,    0       ; if str is null
    je      ret_null        ; return null
    push    rbx             ; rbx -> str
    mov     rbx,    rdi
    call    _ft_strlen

alloc:
    add     rax,    1       ; For the null termination
    mov     rdi,    rax     ; Passes the len as the first malloc argument
    push    rdi
    call    _malloc
    cmp     rax,    0       ; malloc failed
    je      end

copy:
    pop     rdi
    mov     rcx,    rdi     ; set rep loop count
    mov     rdi,    rax     ; set malloc return address as destination
    mov     rsi,    rbx     ; set str as source
    cld
    rep     movsb

end:
    pop     rbx
    ret

ret_null:
    mov     rax,    0
    ret

