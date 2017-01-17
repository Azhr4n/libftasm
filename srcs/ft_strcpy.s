section .text
	global _ft_strcpy
	extern _ft_strlen

_ft_strcpy:
	enter 0, 0

get_len:
	push rdi
	push rsi
	mov rdi, rsi
	call _ft_strlen
	pop rsi
	pop rdi

end_str:
	mov rdx, rdi
	push rax
	sub rcx, rcx
	not rcx
	mov rax, 0
	cld
	repne scasb
	pop rax

cpy:
	dec rdi
	mov rcx, rax
	cld
	rep movsb
	mov rax, rdx

end:
	leave
	ret
