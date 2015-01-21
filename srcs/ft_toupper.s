section .text
global _ft_toupper

_ft_toupper:
	cmp		rdi, 97
	jge		step1
	jmp	    ret1

step1:
	cmp		rdi, 122
	ja		ret1
	sub		rdi, 32
	jmp	 	ret1

ret1:
	mov		rax, rdi
	ret