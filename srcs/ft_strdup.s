section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy

_ft_strdup:
	enter 0, 0
	push rdi
	call _ft_strlen
	add rax, 1
	push rax
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je end
	pop rdx
	pop rsi
	mov rdi, rax
	call _ft_memcpy
end:
	leave
	ret