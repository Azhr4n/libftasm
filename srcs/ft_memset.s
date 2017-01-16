section .text
	global _ft_memset

_ft_memset:
	enter 0, 0
	push rdi
	mov rax, rsi
	mov rcx, rdx
	cld
	rep stosb
	pop rax
	leave
	ret