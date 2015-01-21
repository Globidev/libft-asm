section .text
global _ft_bzero

_ft_bzero:
<<<<<<< HEAD
	test	rsi, rsi
	je		ret1
	mov		rcx, rsi
l1:
	mov		byte [rdi], 0
	inc		rdi
	loop	l1
=======
	test rsi, rsi
	je ret1
	mov rcx, rsi

l1:
	mov byte [rdi], 0
	inc rdi
	loop l1
>>>>>>> b59b40bcdf8bd4c3d9568150ff7fb6c6be6251fe

ret1:
	ret
