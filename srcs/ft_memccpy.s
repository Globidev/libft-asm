section .text
global _ft_memccpy

; rdi -> void *dst
; rsi -> const void *restrict src
; rdx -> int c
; rcx -> size_t n

_ft_memccpy:
	mov 	rax,	rdi					; Set return Value
	cmp		rcx, 	0					; Check rcx
	je 		ret_fail

copy:
    mov     r8, 		[rsi]
    mov     byte [rdi], r8b				; Copy rsi -> rdi
    inc     rdi
	cmp     [rsi], dl					; Search c
    je      ret_sucess
    dec		rcx
    cmp		rcx, 	0					; Check rcx
    je		ret_fail
    inc     rsi
    jmp     copy

ret_fail:
	mov 	rax, 	0
	ret

ret_sucess:
	mov 	rax, rdi
    ret
