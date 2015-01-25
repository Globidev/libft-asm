section .data

null_str    db      "(null)",0xa
null_len    equ     $-null_str
endl        db      0xa

%define STDOUT_FILENO 1
%define SYS_WRITE 0x2000004

section .text

global _ft_puts

; int (const char * str)
;                    |
;                    v
;                   rdi

_ft_puts:
    cmp     rdi,    0               ; puts displays "(null)" when passed NULL
    je      null
    mov     rdx,    0               ; rdx will serve as the string length

strlen:
    cmp     byte [rdi + rdx],   0
    je      write_str
    inc     rdx
    jmp     strlen

write_str:
    mov     rax,    SYS_WRITE       ; write(
    mov     rsi,    rdi             ;   STDOUT_FILENO,
    mov     rdi,    STDOUT_FILENO   ;   str,
                                    ;   len (computed above))
    syscall
    cmp     rax,    -1              ; write failed
    je      end

write_nl:
    mov     rax,    SYS_WRITE       ; write(
    mov     rdi,    STDOUT_FILENO   ;   STDOUT_FILENO,
    mov     rsi,    endl            ;   "\n",
    mov     rdx,    1               ;   1)
    syscall
    cmp     rax,    -1              ; write failed
    je      end
    jmp     ret_success

null:
    mov     rax,    SYS_WRITE       ; write(
    mov     rdi,    STDOUT_FILENO   ;   STDOUT_FILENO,
    mov     rsi,    null_str        ;   null_str,
    mov     rdx,    null_len        ;   null_len)
    syscall
    cmp     rax,    -1              ; write failed
    je      end

ret_success:
    mov     rax,    10              ; always ret 10 on success

end:
    ret
