section .text
	global _ft_memcpy

_ft_memcpy:
	enter 0, 0
	push rdi
	mov rcx, rdx
	cld
	rep movsb
	pop rax
	leave
	ret