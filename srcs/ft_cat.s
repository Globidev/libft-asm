section .data

buff_size   equ     4096

%define STDOUT_FILENO 1
%define SYS_READ 0x2000003
%define SYS_WRITE 0x2000004

section .text
global _ft_cat

; void (int fd)
;           |
;           v
;          rdi

_ft_cat:
    push    rbx
    mov     rbx,    rdi             ; saving fd in rbx (non volatile)
    push    rbp
    mov     rbp,    rsp             ; allocating char[buff_size] on the stack
    sub     rbp,    buff_size       ; rbp points to the buffer (non volatile)

read:
    mov     rax,    SYS_READ        ; read(
    mov     rdi,    rbx             ;   fd,
    mov     rsi,    rbp             ;   buff,
    mov     rdx,    buff_size       ;   buff_size)
    syscall
    cmp     rax,    0               ; read failed
    jle     end

write:
    mov     rdx,    rax             ; write(
    mov     rax,    SYS_WRITE       ;   STDOUT_FILENO,
    mov     rdi,    STDOUT_FILENO   ;   buff,
    mov     rsi,    rbp             ;   size_read)
    syscall
    cmp     rax,    0               ; write failed
    jle     end
    jmp     read                    ; read again

end:
    pop rbp
    pop rbx
    ret
