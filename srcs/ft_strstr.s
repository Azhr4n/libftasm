section .text
	global _ft_strstr
	extern _ft_strlen

_ft_strstr:
	enter 0, 0

	push rdi
	push rsi
	mov rdi, rsi
	call _ft_strlen
	pop rsi
	pop rdi
	push rdi
	push rsi
	cmp rax, 0
	je end
	mov rcx, rax
	
search:
	movzx rbx, byte[rdi]
	movzx rdx, byte[rsi]
	cmp rbx, rdx
	jne reset
	inc rdi
	inc rsi
	dec rcx
	cmp rcx, 0
	je end
	jmp search

reset:
	pop rsi
	pop rdi
	cmp rbx, 0
	je none
	inc rdi
	push rdi
	push rsi
	mov rcx, rax
	jmp search

none:
	mov rax, 0
	leave
	ret

end:
	pop rsi
	pop rax
	leave
	ret
	